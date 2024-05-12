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
class Solution {
public:
    TreeNode* construct(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int>& mpp) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inroot = mpp[root->val];
        int numsleft = inroot - inStart;
        root->left = construct(inorder, inStart, inroot - 1, postorder, postStart, postStart + numsleft - 1, mpp);
        root->right = construct(inorder, inroot + 1, inEnd, postorder, postStart + numsleft, postEnd - 1, mpp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        int n = postorder.size();
        int m = inorder.size();
        for (int i = 0; i < m; ++i) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = construct(inorder, 0, m - 1, postorder, 0, n - 1, mpp);
        return root;
    }
};