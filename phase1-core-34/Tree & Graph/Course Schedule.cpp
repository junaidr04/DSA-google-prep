// Problem: Course Schedule
// Platform: LeetCode
// Link: https://leetcode.com/problems/course-schedule/description/
// time complexity: O(V + E) where V is the number of courses and E is the number of prerequisites, as we need to build the graph and perform a DFS or BFS to detect cycles
// space complexity: O(V + E) where V is the number of courses and E is the number of prerequisites, as we need to store the graph and the visited states for each course

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state)
    {
        state[node] = 1;
        for (int neighbor : adj[node])
        {
            if (state[neighbor] == 1)
            {
                return false;
            }
            else if (state[neighbor] == 0)
            {
                if (dfs(neighbor, adj, state) == false)
                {
                    return false;
                }
            }
        }
        state[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);
        for (auto &pre : prerequisites)
        {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (state[i] == 0)
            {
                if (dfs(i, adj, state) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// TC: O(V + E) where V is the number of courses and E is the number of prerequisites, as we need to build the graph and perform a DFS or BFS to detect cycles
// SC: O(V + E) where V is the number of courses and E is the number of prerequisites, as we need to store the graph and the visited states for each course

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            count++;
            for (int nxt : adj[course])
            {
                indegree[nxt]--;
                if (indegree[nxt] == 0)
                {
                    q.push(nxt);
                }
            }
        }
        return count == numCourses;
    }
};