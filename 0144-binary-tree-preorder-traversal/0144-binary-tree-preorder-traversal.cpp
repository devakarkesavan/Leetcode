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
        vector<int>preorder;
        // preorder(root,ans);
        //iterative approach
        if(root==NULL){
            return preorder;
        }
        // stack<TreeNode*>st;
        // st.push(root);
        // while(!st.empty()){
        //     root = st.top();
        //     st.pop();
        //     ans.push_back(root->val);
        //     if(root->right){
        //         st.push(root->right);
        //     }
        //     if(root->left){
        //         st.push(root->left);
        //     }
        // }
        // return ans;
        TreeNode* curr = root;
        while(curr){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right=NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};