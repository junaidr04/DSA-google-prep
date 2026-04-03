// Problem: Lowest Common Ancestor of a Binary Search Tree
// Platform: LeetCode
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// time complexity: O(h) where h is the height of the binary search tree, as we traverse down the tree at most once
// space complexity: O(h) in the worst case (when the binary search tree is completely unbalanced), O(1) in the best case (when the tree is balanced)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

// TC: O(h) where h is the height of the binary search tree, as we traverse down the tree at most once
// SC: O(1) in the best case (when the tree is balanced), O(h) in the worst case (when the binary search tree is completely unbalanced)

class Solution
{
public:
    // Function ta BST er LCA (Lowest Common Ancestor) ber korbe
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // jotokkhon root NULL na hoy (mane tree er moddhe achi)
        while (root != NULL)
        {
            // jodi p & q duita-i current root er theke choto hoy
            // mane duita node-i left subtree te ache
            if (p->val < root->val && q->val < root->val)
            {
                // tai left side e move kori
                root = root->left;
            }
            // jodi p & q duita-i current root er theke boro hoy
            // mane duita node-i right subtree te ache
            else if (p->val > root->val && q->val > root->val)
            {
                // tai right side e move kori
                root = root->right;
            }
            // jodi uporer kono condition true na hoy
            // mane ekta left e, arekta right e OR root er sathei match
            else
            {
                // current root-i LCA (answer)
                return root;
            }
        }
        // jodi kono reason e root NULL hoye jay (edge case)
        return NULL;
    }
};