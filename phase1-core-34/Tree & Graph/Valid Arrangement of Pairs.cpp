// Problem: Valid Arrangement of Pairs
// Platform: LeetCode
// Link: https://leetcode.com/problems/valid-arrangement-of-pairs/description/
// time complexity: O(E log E) — multiset insert/erase প্রতিটা O(log E), total E edges
// space complexity: O(E) — graph + ans + recursion stack


/*
Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1 
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3 
*/


class Solution {
public:
    unordered_map<int, multiset<int>> graph;
    vector<int> ans;  // flat list — DFS er result eikhane jombe
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> out, in;
        // graph build kori + out/in degree count kori
        for (auto& p : pairs) 
        {
            out[p[0]]++;
            in[p[1]]++;
            graph[p[0]].insert(p[1]);
        }
        
        // start node ber kori: jar out-degree, in-degree theke exactly 1 beshi
        int s = pairs[0][0]; // fallback (circuit case er jonno)
        for (auto& [node, outVal] : out) 
        {
            if (outVal - in[node] == 1) 
            {
                s = node;
                break;
            }
        }
        // DFS chalai start node theke
        dfs(s);
        
        // dfs "dead-end theke push" kore, tai reverse lagbe
        reverse(ans.begin(), ans.end());
        
        // ans ekta flat list [11,9,4,5,1] — eita theke consecutive pair banai
        vector<vector<int>> result;
        for (int i = 0; i + 1 < ans.size(); i++) 
        {
            result.push_back({ans[i], ans[i+1]});
        }
        return result;
    }
    void dfs(int node) 
    {
        // jotokkhon 'node' theke r kono unused edge ache
        while (!graph[node].empty()) 
        {
            int next = *graph[node].begin();       // smallest neighbor (sorted, multiset)
            graph[node].erase(graph[node].begin()); // ei edge ta "use" kore fela — remove
            dfs(next);                              // recursive call
        }
        // dead-end (r kono edge nai) — node ke result e push
        ans.push_back(node);
    }
};