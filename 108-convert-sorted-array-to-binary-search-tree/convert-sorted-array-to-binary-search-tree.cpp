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
    TreeNode* fun(vector<int> &n,int l,int r){
        if(l<=r){
            int m=(l+r)/2;
            TreeNode* pu=new TreeNode(n[m]);
            pu->left=fun(n,l,m-1);
            pu->right=fun(n,m+1,r);
            return pu;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& n) {

        return fun(n,0,n.size()-1);
        
    }
};