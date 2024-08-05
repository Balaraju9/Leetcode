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
int max1=INT_MIN;
int z=0;
    void fun(TreeNode* root,int c){
        if(root==NULL){
            return;
        }
        if(c>max1){
            max1=c;
            z=root->val;
        }
        fun(root->left,c=c+1);
        fun(root->right,c);

    }
    int findBottomLeftValue(TreeNode* root) {
        int c=0;
        fun(root,c);
        return z;
        
    }
};