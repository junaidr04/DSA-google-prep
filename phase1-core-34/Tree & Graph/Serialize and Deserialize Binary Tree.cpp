// Problem: Serialize and Deserialize Binary Tree
// Platform: LeetCode
// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// time complexity: O(n) for both serialization and deserialization, where n is the number of nodes in the binary tree, as we need to visit each node once
// space complexity: O(n) for both serialization and deserialization, as we need to store the serialized string and the deserialized tree in memory

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        queue<TreeNode *> q;
        q.push(root);
        string ans = "";
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                ans += "N,";
            }
            else
            {
                ans += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        TreeNode *root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (tokens[i] == "N")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
            if (tokens[i] == "N")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));