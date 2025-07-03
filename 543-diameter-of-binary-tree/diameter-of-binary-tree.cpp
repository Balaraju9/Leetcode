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
    int max1=0;
    int fun(TreeNode* r){
        if(r==NULL){
            return 0;
        }
        int l=fun(r->left);
        int r1=fun(r->right);
        max1=max(max1,l+r1+1);
        return 1+max(l,r1);
    }
    int diameterOfBinaryTree(TreeNode* r) {
        fun(r);
        return max1-1;
        
    }
};