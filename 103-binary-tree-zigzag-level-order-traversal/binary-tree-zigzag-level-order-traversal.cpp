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
map<int,vector<int>> mp;
void fun(TreeNode* root,int c){
    if(root==NULL){
        return;
    }
    mp[c].push_back(root->val);
    fun(root->left,c=c+1);
    c=c-1;
    fun(root->right,c=c+1);
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int c=0;
        fun(root,c);
        vector<vector<int>> v1;
        int puk=0;
        for(auto &i:mp){
            if(puk==0){

            v1.push_back(i.second);
            puk=1;
            }
            else{
                reverse(i.second.begin(),i.second.end());
                 v1.push_back(i.second);
            puk=0;

            }

        }
        return v1;
    }
};