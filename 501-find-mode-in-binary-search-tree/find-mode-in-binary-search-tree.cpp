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
    void fun(TreeNode* r,unordered_map<int,int> &mp){
        if(r==NULL){
            return;
        }
        fun(r->left,mp);
        mp[r->val]++;
        max1=max(max1,mp[r->val]);
        fun(r->right,mp);
    }
    vector<int> findMode(TreeNode* r) {
        unordered_map<int,int> mp;
        fun(r,mp);
        vector<int> v1;
        for(auto &i:mp){
            if(i.second==max1){
                v1.push_back(i.first);
            }
        }
     return v1;
     
        
    }
};