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
    int height(TreeNode* root,int& maxi){
        if(root==NULL){
            return 0;
        }
        int lhs = max(0,height(root->left,maxi));
        int rhs = max(0,height(root->right,maxi));
        maxi = max(maxi,root->val+lhs+rhs);
        return root->val+max(lhs,rhs);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        height(root,maxi);
        return maxi;
    }
};