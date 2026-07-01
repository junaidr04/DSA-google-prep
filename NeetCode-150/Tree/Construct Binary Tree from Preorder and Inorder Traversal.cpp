// Problem: Construct Binary Tree from Preorder and Inorder Traversal
// Platform: NeetCode
// Link: https://neetcode.io/problems/binary-tree-from-preorder-and-inorder-traversal/question
// time complexity: O(N²); where N is the number of nodes in the binary tree. while loop O(N) for each node
// space complexity: O(H) — recursion call stack


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
    // preStart → preorder এ current root কোন index এ
    // inStart → inorder এ current subtree কোথায় শুরু
    // inEnd → inorder এ current subtree কোথায় শেষ
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int inEnd)
    {
        // inorder er starting point thkee end point porjonto kono element na thkle null..
        if (inStart > inEnd)
            return nullptr;
        // Preorder এ যে index এ আছি, সেটাই এখনকার root
        // যেমন , preorder=[3,9,20] → preStart=0 হলে root=3
        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        // Inorder এ root টা কোথায় আছে খুঁজো
        // যেমন inorder=[9,3,15] → 3 আছে index 1 এ → mid=1
        int mid = inStart;
        while (inorder[mid] != rootVal)
        {
            mid++;
        }
        // Root এর বামে কতটা element আছে সেটা বের করো
        // যেমন mid=1, inStart=0 → বামে 1টা element (9)
        int leftSize = mid - inStart;
        // বাম দিকের subtree বানাও
        // preStart+1 কারণ root এর পরেই left subtree শুরু
        // inStart থেকে mid-1 পর্যন্ত left এর elements
        root->left = helper(preorder, inorder, preStart + 1, inStart, mid - 1);
        // ডান দিকের subtree বানাও
        // preStart+leftSize+1 কারণ left শেষ হওয়ার পরেই right শুরু
        // mid+1 থেকে inEnd পর্যন্ত right এর elements
        root->right = helper(preorder, inorder, preStart + leftSize + 1, mid + 1, inEnd);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // পুরো array দিয়ে শুরু করো
        // preStart=0 (শুরু থেকে), inStart=0, inEnd=শেষ index
        return helper(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};
