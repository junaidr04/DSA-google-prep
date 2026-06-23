// Problem: Subtree of Another Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/subtree-of-another-tree
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
    // এই function চেক করে দুইটা tree সম্পূর্ণ একই কিনা
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // যদি দুইটিই nullptr হয় or খালি tree thake, তাহলে same
        if (p == nullptr && q == nullptr)
            return true;

        // যদি একটি nullptr হয় আর অন্যটি না হয়,তাহলে tree দুইটি same না
        if (p == nullptr || q == nullptr)
            return false;

        // বর্তমান node-এর value একই কিনা চেক করি
        // এবং বাম subtree ও ডান subtree একই কিনা চেক করি
        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    // এই function চেক করে subRoot কি root-এর subtree কিনা
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {

        // root শেষ হয়ে গেলে কিন্তু subRoot পাওয়া না গেলে
        // subtree exist করে না
        if (root == nullptr)
            return false;

        // Empty tree সব tree-এর subtree, তাই ideally true হওয়া উচিত
        if (subRoot == nullptr)
            return true;

        // ১. বর্তমান root থেকেই subRoot শুরু হচ্ছে কিনা দেখি
        // ২. না হলে left subtree-তে খুঁজি
        // ৩. সেখানেও না পেলে right subtree-তে খুঁজি
        return isSameTree(root, subRoot) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};