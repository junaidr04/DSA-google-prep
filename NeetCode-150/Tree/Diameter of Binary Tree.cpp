// Problem: Diameter of Binary Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/diameter-of-binary-tree
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
    int diameter = 0; // ⭐ এই variable পুরো tree জুড়ে এখন পর্যন্ত
                      // পাওয়া সবচেয়ে বড় diameter (edge count) ধরে রাখবে
                      // class variable, তাই recursion এর প্রতিটা call
                      // একই variable access করতে পারবে

    int depth(TreeNode *node)
    {
        // node null মানে এখানে কোনো node নেই
        if (node == nullptr)
            return 0;

        // Left subtree এর depth বের করো (recursive call)
        int l = depth(node->left);

        // Right subtree এর depth বের করো
        int r = depth(node->right);

        // ⭐ এইটাই মূল কাজ এই problem এর জন্য:
        // current node দিয়ে যদি একটা path যায় (left subtree থেকে
        // এই node হয়ে right subtree তে), তাহলে সেই path এর
        // edge count = l + r
        //
        // diameter variable এ সবসময় সবচেয়ে বড়টা রাখো
        // (এখন পর্যন্ত পাওয়া সব node এর মধ্যে compare করে)
        diameter = max(diameter, l + r);

        // এই function টা কিন্তু diameter return করছে না!
        // এটা return করছে শুধু "depth" — যেটা parent node
        // এর কাজে লাগবে (parent নিজের l+r বের করতে এটা ব্যবহার করবে)
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        // depth() call করলে পুরো tree traverse হয়ে যাবে
        // এবং recursion এর ভিতরে ভিতরে diameter variable
        // automatically update হতে থাকবে প্রতিটা node এ
        depth(root);

        // depth() এর return value এখানে দরকার নেই (ignore করলাম)
        // আমাদের আসল answer তো diameter variable এ জমা আছে
        return diameter;
    }
};