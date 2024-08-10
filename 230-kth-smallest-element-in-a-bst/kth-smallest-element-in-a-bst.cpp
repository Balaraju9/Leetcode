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
   
   vector<int> v1;

public:
    void fun(TreeNode* root,int k){
        if(root==NULL){
            return;
        }
        v1.push_back(root->val);
        fun(root->left,k);
        fun(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {

       fun(root,k);
        sort(v1.begin(),v1.end());
 
       return v1[k-1];
        
        
    }
};