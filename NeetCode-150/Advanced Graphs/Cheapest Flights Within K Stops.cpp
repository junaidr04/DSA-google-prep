// Problem: Cheapest Flights Within K Stops
// Platform: NeetCode
// Link: https://neetcode.io/problems/network-delay-time
// time complexity: O(k × E) where E is the number of edges in the graph, as we are using a BFS-like approach to explore the graph up to k stops
// space complexity: O(n) where n is the number of vertices in the graph, as we are using a queue to store the vertices and their distances

/*
Input: n = 4, flights = [[0,1,200],[1,2,100],[1,3,300],[2,3,100]], src = 0, dst = 3, k = 1
Output: 500

Flights:
0→1: 200
1→2: 100
1→3: 300
2→3: 100
Chitro:
0 ──(200)──> 1 ──(300)──> 3
              │
            (100)
              │
              v
              2 ──(100)──> 3

Question: src=0, dst=3, k=1 (max 1 ta stop)
Shob possible route dekhi 0 theke 3 te:

Route A: 0 → 1 → 3

Stops (in-between cities): শুধু city 1 → 1 ta stop
Cost: 200 + 300 = 500
Stop count (1) ≤ k(1) ✅ Valid!

Route B: 0 → 1 → 2 → 3

Stops (in-between cities): city 1 ar city 2 → 2 ta stop
Cost: 200 + 100 + 100 = 400
Stop count (2) > k(1) ❌ Invalid — beshi stop use hoye gese!
Tulona:

Route B sস্তা (400 < 500), kintu allowed na — karon k=1 mane max 1 ta intermediate city diye jawa jabe। Route B te 2 ta city (1 ar 2) diye jete hocche, tai eita reject hobe।

Route A valid (1 ta stop, exactly k er shoman) — tai Answer = 500 ✅

Core concept ta abar bhalo kore bujho:

"Stop" mane ki? Stop mane intermediate city — src ar dst এর majhkhane যে city diye jaite hocche।

0 → 3 (direct) hole = 0 stop
0 → 1 → 3 hole = 1 stop (city 1 ekটা stop)
0 → 1 → 2 → 3 hole = 2 stop (city 1 ar city 2, duita stop)

Pattern: stops = (number of edges used) - 1

Tai k stop allowed মানে max k+1 ta edge/flight use kora jaবে।
Keno eita Dijkstra diye shohoje hoy na?

Normal Dijkstra shudhু "kon route shobcheye kম cost" eita dekhবে — city 2 te pouchate 300 lage (0→1→2), r city 3 te pouchate direct-best route dhorবে 400 (Route B) — stop limit ke completely ignore korবে!

Amader dhoroner jonno ekta "koto edge byabohar korlam" seটা o track korte hobe সাথে সাথে — সেটাই Bellman-Ford er core idea, jekhane amra round-by-round (round 1 = 1 edge use kore kothay pouchano jay, round 2 = 2 edge use kore, etc.) agi।

flights = [[0,1,100],[1,2,100],[0,2,500]]
src=0, dst=2, k=1  (max 2 edge)

Round 0 (i=0):

temp = dist = [0, INF, INF] (copy kori)
Edge(0,1,100): dist[0]=0 (purono value) → temp[1] = 0+100=100
Edge(1,2,100): dist[1] এখনো INF (purono, kারণ dist update hoয়নি) → skip, condition false
Edge(0,2,500): dist[0]=0 → temp[2] = 0+500=500
Round shesh: dist = temp = [0, 100, 500]

Round 1 (i=1):

temp = dist = [0, 100, 500] (copy)
Edge(0,1,100): dist[0]=0 → temp[1] = min(100, 0+100)=100 (change nai)
Edge(1,2,100): dist[1]=100 (ekhon purono/confirmed value theke thik, karon age round e set hoyeche) → temp[2] = 100+100=200 < 500 → update! temp[2]=200
Edge(0,2,500): dist[0]=0 → temp[2] = min(200, 500)=200 (change nai)
Round shesh: dist = [0, 100, 200]

Final: dist[2] = 200 ✅ (thik answer — 0→1→2, 2 edge diye, exactly k=1 stop e)
*/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // dist[i] = source theke city i te pouchate minimum cost
        // shuru te sob infinity (INT_MAX) — jani na koto lage
        vector<int> dist(n, INT_MAX);
        dist[src] = 0; // source theke nijer kache jete cost 0
        // max k+1 ta edge use korte parbo (k stop mane k+1 flight)
        // tai loop k+1 bar chalabo
        for (int i = 0; i < k + 1; i++)
        {
            // *** KEY FIX: temp ekটা COPY, ei round shuru howar shomoy kar dist kemon silo ***
            // amra shob UPDATE ei 'temp' e korবো, 'dist' e na (direct)
            vector<int> temp = dist;
            // shob flight (edge) ekbar kore dekhi
            for (auto &e : flights)
            {
                int u = e[0], v = e[1], w = e[2];
                // dist[u] — 'purono' value use kortesi (ei round er age porjonto)
                // eita guarantee kore je amra ei round e SHUDHU 1 TA notun edge add kortesi
                if (dist[u] != INT_MAX && dist[u] + w < temp[v])
                {
                    // update kori temp e, dist e na — jate ei round er onno
                    // edge gula "purono" dist dekhe, notun update kora value na
                    temp[v] = dist[u] + w;
                }
            }
            // round shesh — ekhon temp er shob notun update, dist e "confirm" kori
            // porer round eshob update gula "purono/confirmed" value hisebe use hobe
            dist = temp;
        }
        // jodi dst te akhono INT_MAX thake, mane max k stop er modhdhe pouchano jay nai
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};