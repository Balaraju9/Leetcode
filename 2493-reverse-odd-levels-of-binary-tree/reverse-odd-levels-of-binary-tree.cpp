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
    void fun(TreeNode* r,TreeNode* r1,int l1,int l2){
        if(r==NULL){
            return;
        }
        if(l1%2==0){
           swap(r1->val,r->val);
            
        }
        fun(r->left,r1->right,l1+1,l2+1);
        fun(r->right,r1->left,l1+1,l2+1);
    }
    TreeNode* reverseOddLevels(TreeNode* r) {
        TreeNode* r1=r;
        fun(r->right,r->left,0,0);
        return r;
        
    }
};