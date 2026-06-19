// Problem: Maximum Depth of Binary Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/maximum-depth-of-binary-tree
// time complexity: O(n); where n is the number of nodes in the binary tree
// space complexity: O(h); where h is the height of the binary tree


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
    int maxDepth(TreeNode *root)
    {

        // Base case: node null মানে আমরা leaf এর নিচে চলে গেছি
        if (root == nullptr)
            return 0;

        // ধরে নাও — এই call ঠিকভাবে left subtree এর সর্বোচ্চ depth দিয়ে দিবে
        int l = maxDepth(root->left);

        // Right subtree এর depth ও একইভাবে বের করো
        int r = maxDepth(root->right);

        // Current node এর depth = (left আর right এর মধ্যে যেটা বড়) + নিজে ১টা node
        return max(l, r) + 1;
    }
};