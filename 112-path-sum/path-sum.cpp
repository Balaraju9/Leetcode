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
    bool pu=false;
    bool fun(TreeNode* r,int t){
       if(r!=NULL && r->right==NULL && r->left==NULL && t-r->val==0){
        
            pu=true;
            return true;
        }
        else if(r==NULL){
           
            return false;
        }
        
        bool l=fun(r->left,t-r->val);
        bool r1=fun(r->right,t-r->val);
        return l||r1;

    }
    bool hasPathSum(TreeNode* r, int t) {
       if(r==NULL){
        return false;
       }
       return fun(r,t);
        return pu;

        
        
    }
};