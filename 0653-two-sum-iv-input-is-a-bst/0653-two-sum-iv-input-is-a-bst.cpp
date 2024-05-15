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
class BstIterator{
        stack<TreeNode*>st;
        bool val = true;
        public:
        BstIterator(TreeNode* root,bool isval){
            val = isval;
            pushAll(root,val);
        }
        bool hasNext(){
            return !st.empty();
        }
        int next(){
            TreeNode* node = st.top();
            st.pop();
            if(!val){
                pushAll(node->right,val);
            }
            else{
                pushAll(node->left,val);
            }
            return node->val;
        }
    private:
        void pushAll(TreeNode* node,bool val){
            while(node!=NULL){
                st.push(node);
                if(val){
                    node = node->right;
                }
                else{
                    node = node->left;
                }
            }
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        BstIterator l(root,false);
        BstIterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k){
                return true;
            }
            if(i+j < k){
                i = l.next();
            }
            else{
                j = r.next();
            }
        }
        return false;
        
    }
};