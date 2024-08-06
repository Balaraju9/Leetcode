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
void fun(TreeNode* root,int c){
    if(root==NULL){
        return;
    }
    max1=max(max1,c);
    fun(root->left,c=c+1);
    c=c-1;
    fun(root->right,c=c+1);

}
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        fun(root,1);

        return  max1;
        
    }
};