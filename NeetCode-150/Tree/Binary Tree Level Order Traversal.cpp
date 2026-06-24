// Problem: Binary Tree Level Order Traversal
// Platform: NeetCode
// Link: https://neetcode.io/problems/level-order-traversal-of-binary-tree/question
// time complexity: O(N); Each node exactly once
// space complexity: O(N); In a perfect binary tree, there are N/2 nodes at the last level. So the max size of the queue = N/2 = O(N)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        // Edge case: empty tree হলে খালি ans return করো
        if (root == nullptr)
            return ans;
        // Root দিয়ে BFS শুরু
        q.push(root);
        while (!q.empty())
        {
            // এই মুহূর্তে queue তে যতটা node = এই level এর node count
            int l = q.size();
            vector<int> level; // এই level এর values রাখবো
            for (int i = 0; i < l; i++)
            {
                // Current node বের করো
                TreeNode *node = q.front();
                q.pop();

                // Value রাখো current level এ
                level.push_back(node->val);

                // Children কে next level এর জন্য queue তে push করো
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // পুরো level টা final answer এ add করো
            ans.push_back(level);
        }
        return ans;
    }
};