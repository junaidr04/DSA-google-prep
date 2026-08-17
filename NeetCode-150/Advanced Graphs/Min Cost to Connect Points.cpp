// Problem: Min Cost to Connect Points
// Platform: NeetCode
// Link: https://neetcode.io/problems/min-cost-to-connect-points/question
// time complexity: O(n² log n) প্রতিটা node pop howar shomoy, baki shob n-1 point er sathe distance calculate kore push kori — eita O(n) per node Total n node process korte hobe — tai O(n²) edge push hote pare Priority queue e push/pop O(log n) (queue size max O(n²) hote pare)
// space complexity: O(n²); Priority queue e worst case shob possible edge thakte pare


/*  
Input: points = [[0,0],[2,2],[3,3],[2,4],[4,2]]

Output: 10

Points:
0: (0,0)
1: (2,2)
2: (3,3)
3: (2,4)
4: (4,2)
Prothome shob distance calculate kori (Manhattan):
0-1: |0-2|+|0-2| = 4
0-2: |0-3|+|0-3| = 6
0-3: |0-2|+|0-4| = 6
0-4: |0-4|+|0-2| = 6
1-2: |2-3|+|2-3| = 2
1-3: |2-2|+|2-4| = 2
1-4: |2-4|+|2-2| = 4
2-3: |3-2|+|3-4| = 2
2-4: |3-4|+|3-2| = 2
3-4: |2-4|+|4-2| = 4
Ekhon Prim's algorithm hate kore chalai (bujhar jonno):

Start: point 0 diye shuru kori. visited = {0}

Step 1: Point 0 theke shob edge dekhi: 0-1(4), 0-2(6), 0-3(6), 0-4(6)
→ Shobcheye choto = 0-1 (weight 4). Point 1 ke MST-te add kori.
visited = {0, 1}, cost = 4

Step 2: Ekhon visited er shob point theke unvisited point er edge dekhi:

Point 0 theke: 0-2(6), 0-3(6), 0-4(6)
Point 1 theke: 1-2(2), 1-3(2), 1-4(4)
→ Shobcheye choto = 1-2 (weight 2) [othoba 1-3, same weight — jekono ekta]. Dhori point 2 nilam.
visited = {0, 1, 2}, cost = 4 + 2 = 6

Step 3: Abar shob edge dekhi visited theke unvisited e:

Point 1 theke: 1-3(2), 1-4(4)
Point 2 theke: 2-3(2), 2-4(2)
→ Shobcheye choto = 1-3 ba 2-3 ba 2-4, sob 2. Dhori point 3 nilam (1-3 diye).
visited = {0, 1, 2, 3}, cost = 6 + 2 = 8

Step 4: Baki shudhu point 4. Dekhi:

Point 1 theke: 1-4(4)
Point 2 theke: 2-4(2)
Point 3 theke: 3-4(4)
→ Shobcheye choto = 2-4 (weight 2). Point 4 add kori.
visited = {0,1,2,3,4}, cost = 8 + 2 = 10
Total cost = 4 + 2 + 2 + 2 = 10 ✅
Key jinis bujhe nao:
Priority Queue always shobcheye choto edge ta select kore — MST-te thaka je kono point theke bahire (unvisited) jawa shob edge er modhdhe.
Cycle create hoy emon edge automatically skip hoye jay — karon amra shudhu unvisited node e jawar edge consider kori. Already visited e thaka point er modhdhe edge thakleo shegula kaje lagbe na (oigula loop e visited check kore skip hoy).
Total 4 ta edge lagse 5 ta point connect korte — general rule: n point connect korte lage exactly n-1 edge (tree er property, cycle thakbe na).
*/


class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        // total koto point ache
        int n = points.size();
        // visited[i] = true mane point i already MST-te add hoye geche
        // shuru te sob false — kono point e visited na
        vector<bool> visited(n, false);
        // min-heap: {distance/weight, point_index} pair store kore
        // greater<> use kore choto weight age ashe (min-heap banano)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // point 0 diye MST shuru kori
        // weight 0 disi karon nijer kache pouchate cost lagbe na
        pq.push({0, 0});
        // MST er total (minimum) cost track korার jonno
        int total = 0;
        // Prim's main loop — jotokkhon queue khali na hoy
        while (!pq.empty())
        {
            // queue theke shobcheye kom weight wala point ber kori
            auto [weight, node] = pq.top();
            pq.pop();
            // STALE CHECK: ei point ta ki already visited (MST-te add kora)?
            // jodi hoy, tahole ei purono/duplicate entry ta skip kori
            if (visited[node])
                continue;
            // ei point ke ekhon MST-te add kori
            visited[node] = true;
            // ei point ke MST-te add korার cost ta total e যোগ kori
            total += weight;
            // ekhon ei notun add howa 'node' theke baki shob UNVISITED
            // point er distance ber kore queue te push kori
            // (jate porer step e shobcheye choto distance wala point ta select hoy)
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    // Manhattan distance formula: |x1-x2| + |y1-y2|
                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    // ei distance ta queue te push kori — future e consider korার jonno
                    pq.push({dist, i});
                }
            }
        }
        // shob point MST-te add hoye গেলে, total ta e amader answer
        // eita hocche minimum cost shob point connect korte
        return total;
    }
};