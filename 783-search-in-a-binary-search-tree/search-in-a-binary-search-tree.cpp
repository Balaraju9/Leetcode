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
TreeNode* pu
;
    void fun(TreeNode* root, int val){
        if(root==NULL){
            return;
        }
        if(root->val==val){
            pu=root;
        }
        fun(root->right,val);
        fun(root->left,val);
    } 
    
    TreeNode* searchBST(TreeNode* root, int val) {
       fun(root,val);
       return pu;

        
    }
};