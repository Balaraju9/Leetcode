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
    int fun(TreeNode* r){
        if(r==NULL){
            return 0;
        }
        int l=r->val+fun(r->left);
        int r1=r->val+fun(r->right);
         max1=max(l+r1-r->val,max1);
         max1=max(max1,r->val);
         max1=max(max1,l);
         max1=max(max1,r1);
         int pu=max(r->val,l);
         pu=max(pu,r1);
        return pu;

    }
    int maxPathSum(TreeNode* r) {
        fun(r);
        return max1;
    }
};