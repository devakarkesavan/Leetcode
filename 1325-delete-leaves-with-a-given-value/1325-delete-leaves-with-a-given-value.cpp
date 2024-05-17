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
private:
    void rec(TreeNode* &node, int target){
        if(!node) return;
        rec(node->left, target);
        rec(node->right, target);
        if(node->left==NULL && node->right==NULL && node->val==target) node = NULL;
        return;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        rec(root, target);
        return root;
    }
};