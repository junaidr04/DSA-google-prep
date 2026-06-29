// Problem: Kth Smallest Integer in BST
// Platform: NeetCode
// Link: https://neetcode.io/problems/kth-smallest-integer-in-bst/question
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
    int ans = 0, count = 0;
    void Inorder(TreeNode *node, int k)
    {
        if (node == nullptr)
            return;

        // আগে বামে যাও (smaller values আগে আসবে)
        Inorder(node->left, k);

        // Current node visit করলাম → count বাড়াও
        count++;

        // k তম element পেয়ে গেছি!
        if (count == k)
        {
            ans = node->val;
            return; // ✅ Early termination — বাকি tree visit করার দরকার নেই
        }

        // ডানে যাও (larger values)
        // Early termination এর কারণে k পাওয়ার পর এই line execute হবে না
        Inorder(node->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        Inorder(root, k);
        return ans;
    }
};