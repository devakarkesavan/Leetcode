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
    void totalsum(int &sum,TreeNode* root){
        
        if(root->left){
            totalsum(sum,root->left);
        }
        sum+=root->val;
        if(root->right){
            totalsum(sum,root->right);
        }
    }
    TreeNode* change(TreeNode* root,int &sum){
        if(!root){
            return root;
        }
        change(root->left,sum);
        int k = sum-root->val;
        root->val = sum;
        sum = k;
        change(root->right,sum);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        totalsum(sum,root);
        TreeNode* temp = change(root,sum);
        return temp;
    }
};