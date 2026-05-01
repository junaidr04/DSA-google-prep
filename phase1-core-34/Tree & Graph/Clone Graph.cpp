// Problem: Clone Graph
// Platform: LeetCode
// Link: https://leetcode.com/problems/clone-graph/description/
// time complexity: O(V + E) where V is the number of nodes and E is the number of edges, as we need to visit each node and edge once
// space complexity: O(V) where V is the number of nodes, for the hash map storing the cloned nodes and the recursion stack in the worst case

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    // //dfs func create korechi, jekhane amra node ke clone korbo and tar neighbors ke recursively clone korbo. visited map use kore amra check korbo je node already clone hoyeche kina, jodi hoye thake tahole se clone return korbo, na hole notun clone create kore visited map e store korbo and tar neighbors ke recursively clone korbo.
    Node *dfs(Node *node, unordered_map<Node *, Node *> &visited)

    ////jodi agee thake thle reuse krbo, and jodi na thake map a thle banaite hbe..
    {
        if (visited.find(node) != visited.end())
        {
            return visited[node];
        }

        // na thkle create korbo..
        Node *clone = new Node(node->val);
        visited[node] = clone;

        // neighbors ke recursively clone korbo..clone node neighbor a set kora..Neighbors set করা মানেই edges copy করা।
        for (auto neigh : node->neighbors)
        {
            clone->neighbors.push_back(dfs(neigh, visited));
        }
        return clone;
    }
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        ////hashmap use kore node ke copy kora jai...
        unordered_map<Node *, Node *> visited;
        return dfs(node, visited);
    }
};