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
    bool balu=true;
    int x1,x2;
    unordered_map<int,int> mp;
    void fun(TreeNode* root,int x){
        if(root==NULL){
            return;
        }
        if(root!=NULL && root->left!=NULL && root->right!=NULL){
            if(root->left->val==x1 && root->right->val==x2){
                balu=false;
            }
            else    if(root->left->val==x2 && root->right->val==x1){
                balu=false;
            }
        }
        mp[root->val]=x;
        fun(root->left,x+1);
        fun(root->right,x+1);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        x1=x;
        x2=y;
        fun(root,0);
        int z=0;
        if(balu==false){
            return false;
        }
      
        return  mp[x]==mp[y];
        
    }
};