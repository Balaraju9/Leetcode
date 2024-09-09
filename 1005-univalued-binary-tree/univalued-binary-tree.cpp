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
    bool pu=true;
    void fun(TreeNode* root){
        if(root==NULL || mp.size()>1){
            return;
        }
        mp[root->val]++;
        if(mp.size()>1){
            pu=false;
        }
        fun(root->left);
        fun(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        fun(root);
        return pu;
        
    }
};