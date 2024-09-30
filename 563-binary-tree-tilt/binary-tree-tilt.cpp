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
    int s=0;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
       
        int l=fun(root->left);
        int r=fun(root->right);
        s+=abs(l-r);
        return root->val+l+r;

    }
    int findTilt(TreeNode* root) {
        fun(root);
        return s;
        
    }
};