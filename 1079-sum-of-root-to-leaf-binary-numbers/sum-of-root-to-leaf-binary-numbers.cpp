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
string s;
    void fun(TreeNode* root,string s){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            v1.push_back(s+to_string(root->val));
        }
        fun(root->left,s+to_string(root->val));
         fun(root->right,s+to_string(root->val));

    }
    
    int sumRootToLeaf(TreeNode* root) {

        fun(root,"");
        long long k1=0;
        for(auto &i:v1){
            k1+=stoll(i, nullptr, 2); 
        }
        
        return k1;
        
    }
};