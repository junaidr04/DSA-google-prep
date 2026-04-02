// Problem: Binary Tree Level Order Traversal
// Platform: LeetCode
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
// time complexity: O(n) where n is the number of nodes in the binary tree, as we visit each node once
// space complexity: O(n) in the worst case (when the binary tree is completely unbalanced), O(w) where w is the maximum width of the tree in the best case (when the tree is balanced)

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        if (root == NULL)
            return ans;
        while (!q.empty())
        {
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};