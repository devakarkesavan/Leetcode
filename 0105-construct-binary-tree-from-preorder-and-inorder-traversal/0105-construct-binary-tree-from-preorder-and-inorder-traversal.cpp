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
    TreeNode* construct(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inroot = mpp[root->val];
    int numsLeft = inroot - inStart;
    root->left = construct(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inroot - 1, mpp);
    root->right = construct(preorder, preStart + numsLeft + 1, preEnd, inorder, inroot + 1, inEnd, mpp);
    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int ,int>mpp;
        int n = preorder.size();
        int m = inorder.size();
        for(int i=0;i<m;i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = construct(preorder,0,n-1,inorder,0,m-1,mpp);
        return root;
    }
};