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
int z=0;
    int rangeSumBST(TreeNode* r, int l, int h) {

        if(r==NULL){
            return z;
        }
        if(r->val>=l && r->val<=h){
            z=z+r->val;
           
        }
         rangeSumBST(r->left,l,h);
          rangeSumBST(r->right,l,h);
        
        return z;

        
    }
};