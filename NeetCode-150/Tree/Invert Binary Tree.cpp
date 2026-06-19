// Problem: Invert Binary Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/invert-binary-tree
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
    TreeNode *invertTree(TreeNode *root)
    {

        // Base case: node null হলে মানে আমরা leaf এর নিচে চলে গেছি
        if (root == nullptr)
            return nullptr;

        // Left subtree কে recursively invert করো
        // এই call শেষ হলে root->left এর নিচের পুরো subtree
        // ভিতরে ভিতরে already invert হয়ে যাবে
        // (কিন্তু root->left pointer টা এখনো same node কে point করছে)
        invertTree(root->left);

        // একইভাবে right subtree কেও recursively invert করো
        invertTree(root->right);

        // এখন current root এর left আর right subtree
        // দুইটাই internally invert হয়ে গেছে।
        // শুধু বাকি আছে — এই node এর level এ left/right swap করা
        swap(root->left, root->right);

        // Invert হওয়া root return করো
        // (caller — মানে parent node — এটা ব্যবহার করবে না,
        //  কারণ root->left pointer আগে থেকেই same node কে point করছিল,
        //  কিন্তু convention হিসেবে root return করতে হয়)
        return root;
    }
};
