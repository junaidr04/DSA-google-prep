// Problem: Valid Binary Search Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/valid-binary-search-tree/question
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
    bool dfs(TreeNode *node, int min, int max)
    {

        // Null node মানে valid — base case
        if (node == nullptr)
            return true;

        // Current node valid range এর বাইরে → invalid BST
        if (node->val <= min || node->val >= max)
            return false;

        // Left এ গেলে max = current val (left সবসময় ছোট)
        // Right এ গেলে min = current val (right সবসময় বড়)
        // দুই দিকেই valid হলে তবেই true
        return dfs(node->left, min, node->val) &&
               dfs(node->right, node->val, max);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        // Root এর কোনো boundary নেই
        return dfs(root, INT_MIN, INT_MAX);
    }
};