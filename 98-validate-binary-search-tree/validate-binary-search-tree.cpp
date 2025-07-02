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
    bool fun(TreeNode* r,long long max1,long long min1){
        if(r==NULL){
            return true;
        }
        if(!(r->val>min1 && r->val<max1)){
            return false;
        }

        bool l=fun(r->left,r->val,min1);
        bool ri=fun(r->right,max1,r->val);
        return l&&ri;

    }
    bool isValidBST(TreeNode* r) {
        if(!r->left && !r->right) return true;
        return fun(r,LLONG_MAX,LLONG_MIN);
        
    }
};