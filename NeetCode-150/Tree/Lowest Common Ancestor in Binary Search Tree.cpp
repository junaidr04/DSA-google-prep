// Problem: Lowest Common Ancestor in Binary Search Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/lowest-common-ancestor-in-binary-search-tree
// time complexity: O(h); where h is the height of the binary tree
// space complexity: O(1); constant space used


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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // curr দিয়ে tree traverse করবো, root থেকে শুরু
        TreeNode *curr = root;
        while (true)
        {
            // দুজনেই curr এর বামে → left subtree তে যাও
            if (p->val < curr->val && q->val < curr->val)
            {
                curr = curr->left;
            }

            // দুজনেই curr এর ডানে → right subtree তে যাও
            else if (p->val > curr->val && q->val > curr->val)
            {
                curr = curr->right;
            }

            // Split হয়ে গেছে! মানে:
            // case 1: p বামে, q ডানে (বা উল্টো)
            // case 2: curr নিজেই p বা q
            // → এই node-ই LCA
            else
            {
                return curr;
            }
        }
    }
};