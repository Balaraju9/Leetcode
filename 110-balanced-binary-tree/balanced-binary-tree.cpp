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
    bool puk=true;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;

        }
        int l=1+fun(root->left);
        int r=1+fun(root->right);
        if(abs(l-r)>1){
            puk=false;

        }
        return max(l,r);
        
    }
    bool isBalanced(TreeNode* root) {
        fun(root);
        return puk;

        
    }
};