// Problem: Binary Tree Maximum Path Sum
// Platform: NeetCode
// Link: https://neetcode.io/problems/binary-tree-maximum-path-sum/question
// time complexity: O(N); while loop O(N) for each node
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
    int ans = INT_MIN; // যেকোনো negative value handle করতে INT_MIN
    int dfs(TreeNode *root)
    {

        // Null node এর contribution = 0
        if (root == nullptr)
            return 0;
        // Negative হলে 0 নাও — মানে ওই দিক skip করো
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // এই node কে root ধরলে max path = দুইদিক + নিজে
        ans = max(ans, root->val + left + right);

        // Parent কে একটাই দিক দিতে পারবো
        // যে দিকে বেশি gain সেটাই নাও
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};