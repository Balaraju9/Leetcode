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
int c=0;
void fun(TreeNode* root,vector<string> &v1,string s){
    if(root->left==NULL && root->right==NULL){
        s=s+to_string(root->val);
        
        v1.push_back(s);
        
        

        return;
    }
    s=s+to_string(root->val)+"->";
    if(root->left!=NULL){
    fun(root->left,v1,s);
    }
    if(root->right!=NULL){
    
    fun(root->right,v1,s);
    }
}

    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> v1;
      string s="";
      fun(root,v1,s);
        return v1;
    }
};