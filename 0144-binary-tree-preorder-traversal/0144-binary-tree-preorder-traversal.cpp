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
    // Recursive approach
    // void preorder(TreeNode* root,vector<int> &ans){
    //     if(root==NULL){
    //         return;
    //     }
    //     ans.push_back(root->val);
    //     preorder(root->left,ans);
    //     preorder(root->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        // preorder(root,ans);
        //iterative approach
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            if(root->right){
                st.push(root->right);
            }
            if(root->left){
                st.push(root->left);
            }
            ans.push_back(root->val);
        }
        return ans;
    }
};