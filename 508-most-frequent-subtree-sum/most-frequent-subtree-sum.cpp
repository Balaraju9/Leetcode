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
    int max1=INT_MIN;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l=fun(root->left);
        int r=fun(root->right);
        mp[root->val+l+r]++;
        max1=max(max1,mp[root->val+l+r]);
        return root->val+l+r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        fun(root);
        vector<int> v1;
        for(auto &i:mp){
          if(i.second==max1){
            v1.push_back(i.first);
          }
        

        
        }
        sort(v1.begin(),v1.end());
            return v1;
    }
};