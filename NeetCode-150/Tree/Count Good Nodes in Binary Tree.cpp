// Problem: Count Good Nodes in Binary Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/count-good-nodes-in-binary-tree/question
// time complexity: O(N); Each node exactly once
// space complexity: O(H) — recursion call stack


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
    int count = 0;
    void dfs(TreeNode *node, int maxSoFar)
    {
        if (node == nullptr)
            return;

        // এই node পর্যন্ত path এ এটাই maximum → good node!
        if (node->val >= maxSoFar)
            count++;

        // max update করে নিচে নামো
        dfs(node->left, max(maxSoFar, node->val));
        dfs(node->right, max(maxSoFar, node->val));
    }
    int goodNodes(TreeNode *root)
    {
        dfs(root, root->val); // root নিজে সবসময় good node
        return count;
    }
};