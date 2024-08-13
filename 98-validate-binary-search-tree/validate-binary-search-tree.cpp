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
    vector<int> v1;
    void fun(TreeNode* root){
        if(root==NULL){
            return;
        }
        fun(root->left);
        v1.push_back(root->val);
        fun(root->right);

    }
    bool isValidBST(TreeNode* root) {
        fun(root);
       unordered_map<int,int> mp;
       for(auto &i:v1){
        mp[i]++;
       }
       vector<int> v2=v1;
      
       sort(v2.begin(),v2.end());
       if(v1==v2 && v1.size()==mp.size()){
        return true;
       }
       return false;
        
    }
};