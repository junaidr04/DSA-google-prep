// Problem: Balanced Binary Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/balanced-binary-tree
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
    bool bal = true; // ⭐ পুরো tree জুড়ে balanced কিনা track করবে
                     // শুরুতে true ধরে নিচ্ছি, কোথাও unbalanced
                     // পেলে false করে দিবো (একবার false হলে আর true হবে না)

    int depth(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        // Left subtree এর height বের করো
        int l = depth(node->left);

        // Right subtree এর height বের করো
        int r = depth(node->right);

        // ⭐ মূল balance check:
        // left আর right height এর পার্থক্য যদি 1 এর বেশি হয়
        // (abs() ব্যবহার করছি কারণ left বড় হতে পারে অথবা right বড় হতে পারে,
        //  দুই ক্ষেত্রেই unbalanced)
        if (abs(l - r) > 1)
        {
            bal = false; // এই node এ unbalanced পাওয়া গেছে..... পুরো tree এর জন্য answer false হয়ে গেলো
        }

        // এই function এর "official" কাজ — height return করা
        // (Maximum Depth problem এর exact same formula)
        // parent node এই value ব্যবহার করবে নিজের height বের করতে
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        // depth() call করলে পুরো tree traverse হবে,
        // আর recursion এর ভিতরে ভিতরে bal variable
        // automatically update হতে থাকবে যদি কোথাও unbalanced পাওয়া যায়
        depth(root);

        // depth() এর return value (root এর height) এখানে দরকার নেই
        // আসল answer bal variable এ জমা আছে
        return bal;
    }
};