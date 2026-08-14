// Problem: Course Schedule
// Platform: NeetCode
// Link: https://neetcode.io/problems/course-schedule
// time complexity: O(V + E) where V is the number of courses and E is the number of prerequisites
// space complexity: O(V + E) for the adjacency list and state array


class Solution
{
    // 3-state DFS diye cycle detect kori
    // state: 0 = unvisited, 1 = visiting (recursion stack e ache), 2 = done/safe
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state)
    {
        // ei node ekhono "visiting" state e ache — mane ekhono processing shesh hoy nai..tobuo আবার এখানে পৌঁছালাম — eiটা cycle!
        if(state[node] == 1)
            return false;
        // ei node age theকেই safely verify hoye গেছে (kono cycle nai)
        // tai eikhane আবার visit korার dorkar nai, শুধু বলে দাও "safe"
        if(state[node] == 2)
            return true;
        state[node]=1;   // "visiting" mark kore dilam — process shuru hocche
        for(int neigh:adj[node])
        {
            // jekono ekটা neighbor e cycle pele, shathe shathe false propagate koro
            if(!dfs(neigh, adj, state))
            {
                return false;
            }
        }
        state[node]=2;   // shob dependency safely check hoye গেছে — ei node ekhon "done"
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // adjacency list banাi — [a,b] mane a nite b lagবে, tai a -> b edge
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);   // shব course "unvisited" diye shuru
        for(auto& p:prerequisites)
        {
            int a=p[0], b=p[1];
            adj[a].push_back(b);
        }
        
        // protিটা course check kori (disconnected component gula o cover korার jonno)
        for(int i=0; i<numCourses; i++)
        {
            if(state[i] == 0)   // ekhono unvisited hole DFS chalao
            {
                if(!dfs(i,adj,state))
                {
                    return false;   // kothaও cycle pele shathe shathe false
                }
            }
        }
        return true;   // shব course check hoye গেলো, kono cycle nai
    }
};