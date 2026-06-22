// Problem: Same Binary Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/same-binary-tree
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        // Case 1: দুইটা node ই null মানে এই subtree তে
        if (p == nullptr && q == nullptr)
            return true;

        // Case 2: একটা null আরেকটা না — structure আলাদা, false
        // অথবা দুইটাই non-null কিন্তু values আলাদা — false
        // এই তিনটার যেকোনো একটা true হলেই same না
        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;

        // Case 3: এই পর্যন্ত আসা মানে —
        // দুইটাই non-null ✅ এবং values same ✅
        // এখন recursively check করো:
        // p এর left subtree == q এর left subtree?
        // AND
        // p এর right subtree == q এর right subtree?
        // দুইটাই true হলে তবেই পুরো tree same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};