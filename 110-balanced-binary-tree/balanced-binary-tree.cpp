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
int sul=0,z=0;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        z++;
        int p1=1+fun(root->left);
        int p2=1+fun(root->right);
        if(abs(p1-p2)<=1){
            sul++;
        }
       
        
        return max(p1,p2);
    }
    bool isBalanced(TreeNode* root) {
        

     fun(root);
   return z==sul;
        
    }
};