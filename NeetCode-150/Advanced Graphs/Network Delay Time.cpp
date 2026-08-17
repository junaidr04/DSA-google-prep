// Problem: Network Delay Time
// Platform: NeetCode
// Link: https://neetcode.io/problems/network-delay-time
// time complexity: O(E log V) where E is the number of edges and V is the number of vertices in the graph, as we are using a priority queue (min-heap) to perform Dijkstra's algorithm
// space complexity: O(V + E) for storing the graph in an adjacency list and the distance array


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // dist[i] = source (k) theke node i te pouchate koto shomoy lagbe
        // shuru te sob INT_MAX (infinity) — mane akhono jani na koto lage
        // size n+1 karon node label 1 theke n (0-indexed na)
        vector<int> dist(n+1, INT_MAX);
        
        // adjacency list: adj[u] = {v, w} pairs list
        // mane u theke kon kon node e (v) koto weight (w) diye jawa jay
        vector<vector<pair<int,int>>> adj(n+1);
        
        // min-heap priority_queue — {distance, node} pair store kore
        // greater<> use kora hoyeche jate shobcheye CHOTO distance shobar age ashe
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        
        // source node (k) er nijer kache pouchate 0 shomoy lage
        dist[k] = 0;
        
        // BFS/Dijkstra shuru korar jonno source ke queue te push kori
        q.push({0, k});
        
        // times array theke shob edge (u -> v, weight w) ber kore
        // adjacency list e sajiye rakhi (graph banano)
        for (auto& t : times) 
        {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }
        // Dijkstra main loop — jotokkhon queue khali na hoy
        while (!q.empty()) 
        {
            // queue theke shobcheye kom distance wala node ber kori
            auto [d, node] = q.top();
            q.pop();
            
            // STALE CHECK: ei entry ta ki purono/outdated?
            // jodi already amra 'node' er jonno choto distance peye gie thaki,
            // tahole ei entry ta ignore kore dei (kaje lagbe na)
            if (d > dist[node])
                continue;
            
            // 'node' er shob neighbor gula ghurey dekhi
            for (auto& [neigh, weight] : adj[node]) 
            {
                // RELAXATION step: 
                // node porjonto giye + ei edge diye neighbor e gele
                // jodi eta age jana 'dist[neigh]' theke choto hoy,
                // tahole eita e amader notun/better path
                if (dist[node] + weight < dist[neigh]) 
                {
                    dist[neigh] = dist[node] + weight;
                    // notun update kora distance ta queue te push kori
                    // jate porer bar eita theke abar explore kora jay
                    q.push({dist[neigh], neigh});
                }
            }
        }
        
        // ekhon shob node er shortest distance ber kore fellam
        // ekhon dekhi shobcheye deri kore (max time) kon node e pouchay
        int maxTime = 0;
        for (int i = 1; i <= n; i++) 
        {
            // jodi kono node akhono INT_MAX thake,
            // mane sheikhane kono bhabei pouchano jay nai — signal fail
            if (dist[i] == INT_MAX)
                return -1;
            // shobcheye boro distance ta track kori (max)
            maxTime = max(maxTime, dist[i]);
        }
        // ei max value e holo answer — 
        // shobcheye deri kore pouchano node porjonto shomoy
        return maxTime;
    }
};