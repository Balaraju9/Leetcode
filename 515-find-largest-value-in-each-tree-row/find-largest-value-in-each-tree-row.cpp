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
    void fun(TreeNode* r,  map<int,priority_queue<int>> &mp,int i){
        if(r==NULL){
            return;
        }
        mp[i].push(r->val);

        fun(r->left,mp,i+1);
        fun(r->right,mp,i+1);
    }
    vector<int> largestValues(TreeNode* r) {
        map<int,priority_queue<int>> mp;
        fun(r,mp,0);
        vector<int> v1;
        for(auto &i:mp){
            v1.push_back(i.second.top());
        }
        return v1;
        
    }
};