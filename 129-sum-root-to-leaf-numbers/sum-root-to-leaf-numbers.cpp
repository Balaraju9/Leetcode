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
vector<string> v1;
    void fun(TreeNode* r,string s){
        if(r!=NULL && r->left==NULL && r->right==NULL){
            v1.push_back(s+to_string(r->val));
            return;
        }
        if(r==NULL){
            return;
        }


        fun(r->left,s+to_string(r->val));
        fun(r->right,s+to_string(r->val));
    }

    int sumNumbers(TreeNode* r) {
        fun(r,"");
        int ans=0;
        for(long long i=0;i<v1.size();i++){
            ans+=stoll(v1[i]);


        }
        return ans;
        
    }
};