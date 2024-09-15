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
    unordered_map<int,int> mp;
    bool puk=false;
    void fun(TreeNode* root,int k){
        if(root==NULL || puk==true){
            return;
        }
      
            if(mp[root->val]>=1 ){
                puk=true;
            }
            else{
                mp[k-root->val]++;
            }
        
        fun(root->left,k);
        fun(root->right,k);

    }
    bool findTarget(TreeNode* root, int k) {
        fun(root,k);
        return puk;
        
    }
};