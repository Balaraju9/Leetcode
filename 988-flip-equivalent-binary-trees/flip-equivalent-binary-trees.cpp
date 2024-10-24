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
        if(r1==NULL && r2!=NULL){
            return false;
        }
        else if(r1!=NULL && r2==NULL){
            return false;
        }
        else if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1->val != r2->val){
            return false;
        }
        bool l=fun(r1->left,r2->right);
        bool r=fun(r1->right,r2->left);
        bool l1=fun(r1->left,r2->left);
        bool l2=fun(r1->right,r2->right);
        return (l&&r) || (l1&&l2);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2!=NULL){
            return false;
        }
         else if(root2==NULL && root1!=NULL){
            return false;
        }
        return fun(root1,root2);
        
    }
};