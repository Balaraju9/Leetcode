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
    bool fun(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2!=NULL || r1!=NULL && r2==NULL){
            return false;
        }
        else if(r1==NULL && r2==NULL){
            return true;
        }
        else if(r1->val !=r2->val){
            return false;
        }
        return fun(r1->left,r2->right) && fun(r1->right,r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)){
            return false;
        }
        return fun(root->left,root->right);
        
    }
};