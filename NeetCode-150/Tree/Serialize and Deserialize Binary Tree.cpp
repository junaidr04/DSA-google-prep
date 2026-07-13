// Problem: Serialize and Deserialize Binary Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/serialize-and-deserialize-binary-tree/question
// time complexity: O(N); Each node exactly once
// space complexity: O(N) — recursion call stack


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

class Codec
{
public:
    // Tree কে String এ convert করার function
    string serialize(TreeNode *root)
    {
        // যদি tree খালি হয় → empty string return করো
        if (!root)
            return "";

        // Queue বানাও — BFS এর জন্য
        queue<TreeNode *> q;

        // Root দিয়ে শুরু করো
        q.push(root);

        // final string জমা হবে
        string ans = "";

        // Queue খালি না হওয়া পর্যন্ত চলো
        while (!q.empty())
        {
            // Queue এর সামনের node নাও
            TreeNode *curr = q.front();

            // সেটা queue থেকে বের করো
            q.pop();

            // যদি node টা null হয়
            if (curr == NULL)
            {
                // "N," লিখো → null মানে N
                ans += "N,";
                // null node এর কোনো child নেই → কিছু push করবো না
            }
            else
            {
                // node এর value string এ যোগ করো + comma
                // যেমন val=3 হলে → "3,"
                ans += to_string(curr->val) + ",";

                // Left child queue তে দাও
                // null হলেও দাও — পরে "N," হিসেবে track হবে
                q.push(curr->left);

                // Right child queue তে দাও
                q.push(curr->right);
            }
        }
        return ans;
    }
};