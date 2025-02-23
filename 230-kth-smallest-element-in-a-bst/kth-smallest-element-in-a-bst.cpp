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
   
   priority_queue<int> q;

public:
    void fun(TreeNode* root,int k){
        if(root==NULL){
            return;
        }
        q.push(root->val);
        while(q.size()>k){
            q.pop();

        }
        fun(root->left,k);
        fun(root->right,k);
    }
  
    int kthSmallest(TreeNode* root, int k) {

       fun(root,k);
       return q.top();
        
        
    }
};