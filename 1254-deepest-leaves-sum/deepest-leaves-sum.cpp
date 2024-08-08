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
int max1=INT_MIN,z=0;
void fun(TreeNode* root,int c){
    if(root==NULL){
        return;
    }
    max1=max(max1,c);
    fun(root->left,c=c+1);
    c=c-1;
    
    fun(root->right,c=c+1);
      max1=max(max1,c);

}
void fun1(TreeNode* root,int c){
    if(root==NULL){
        return;
    }
    if(c==max1){
        z=z+root->val;

    }
    fun1(root->left,c=c+1);
    c=c-1;
    
    fun1(root->right,c=c+1);
        if(c==max1){
        z=z+root->val;

    }

}


    int deepestLeavesSum(TreeNode* root) {
        int c=0;
        fun(root,c);
         fun1(root,c);
         return z;
      
        
        
    }
};