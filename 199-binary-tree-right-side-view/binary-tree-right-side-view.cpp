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
map<int,int> mp;
    void rightview(TreeNode* root,int c){
        if(root==NULL){
            return;
        }
        mp[c]=root->val;
        rightview(root->left,c=c+1);
        c=c-1;
        rightview(root->right,c=c+1);
        

    }
    vector<int> rightSideView(TreeNode* root) {
        int c=0;
        vector<int> v1;
        rightview(root,c);
        for(auto &i:mp){
            v1.push_back(i.second);
        }
        return v1;

        
    }
};