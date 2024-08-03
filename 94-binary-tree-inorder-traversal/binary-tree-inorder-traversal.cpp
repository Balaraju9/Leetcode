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
void fun(TreeNode* root,vector<int> &v1){
    if(root==NULL){
      
        return;
    }
    fun(root->left,v1);
    v1.push_back(root->val);
    fun(root->right,v1);


}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v1;
        fun(root,v1);
        return v1;
        
    }
};