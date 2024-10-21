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
    // int max2=0;
    int  fun(TreeNode* root){
       if(root==NULL){
        return 9999;
       }
       if(root!=NULL && root->left==NULL && root->right==NULL){
        return 1;
       }
       int l=1+fun(root->left);
       int r=1+fun(root->right);
       return min(l,r);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){ return 0;}
        return fun(root);
        
    }
};