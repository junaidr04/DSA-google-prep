// Problem: Number of Connected Components in an Undirected Graph
// Platform: NeetCode
// Link: https://neetcode.io/problems/number-of-connected-components-in-an-undirected-graph
// time complexity: O(V + E) where V is the number of nodes and E is the number of edges
// space complexity: O(V+ E) for the adjacency list and visited array

class Solution
{
    // dfs function: ekটা component er shob node visit kore mark kore dey
    // eikhane cycle check ba parent track korার dorkar nai, karon amra
    // shudhu "kotogulo alada group ache" eta jante chai, cycle/order na
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
    {
        // current node ke visited mark kore dilam
        visited[node] = true;
        // ei node er shob neighbor loop kore dekhchi
        for(int neigh : adj[node])
        {
            // neighbor ta jodi ekhono visited na hoy, tahole recursively
            // shei neighbor e giye tar shob connection o explore kore feli
            // (eভাবে puro component ta ekbare mark hয়ে jaবে)
            if(!visited[neigh])
            {
                dfs(neigh, adj, visited);
            }
            // neighbor already visited hole kichu korার dorkar nai,
            // already onno kono call theke cover hয়ে গেছে
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        // visited array: kon kon node already kono component er
        // moddhe dekha hয়ে গেছে, track korার jonno
        vector<bool> visited(n, false);
        // adjacency list: proti node er neighbor list rakhar jonno
        vector<vector<int>> adj(n);
        // component count rakhার variable, shuru te 0
        int count = 0;
        // Adjacency list build 
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];
            // undirected graph, tai edge ta dui dikei kaj kore
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // Shob node loop kore component count kora 
        for(int i = 0; i < n; i++)
        {
            // jodi ei node ekhono kono DFS theke visited na hoy,
            // tahole eta ekটা "notun" component er shuru
            if(!visited[i])
            {
                count++;              // notun component pawa গেছে, count baralam
                dfs(i, adj, visited); // ei component er shob node ekbare mark kore feli
            }
            // jodi already visited hoy, mane eta age kono onno
            // dfs call theke already kono component er ongsho hisebe
            // cover hয়ে গেছে -- notun kore count korার dorkar nai
        }
        // shob node process shesh, total koyta component paওয়া গেলো shetai return
        return count;
    }
};