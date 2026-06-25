// Problem: Binary Tree Right Side View
// Platform: NeetCode
// Link: https://neetcode.io/problems/binary-tree-right-side-view/question
// time complexity: O(N); Each node exactly once
// space complexity: O(N);


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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root == nullptr)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            vector<int> v;
            int l = q.size(); // এই level এ কতটা node
            for (int i = 0; i < l; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            // প্রতিটা level এর শেষ element = right side থেকে visible
            ans.push_back(v[l - 1]);
        }
        return ans;
    }
};