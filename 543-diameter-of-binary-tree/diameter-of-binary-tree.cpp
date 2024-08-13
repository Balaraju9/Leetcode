/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
int max1=INT_MIN;
    int fun(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int z = 1 + fun(root->left);
        int z1 = 1 + fun(root->right);
        return max(z, z1);
    }
    int fun1(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int z = 1 + fun1(root->left);
        int z1 = 1 + fun1(root->right);
        return max(z, z1);
    }
    void balu(TreeNode* root){
        if(root==NULL){
            return;
        }
        max1=max(max1,fun(root->left)+fun(root->right));

        balu(root->left);
        balu(root->right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        balu(root);
        return max1;
    }
};