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
int min1=INT_MAX;
void fun(TreeNode* root){
    if(root==NULL){
        return;
    }
    v1.push_back(root->val);
    fun(root->left);
    fun(root->right);
}
    int getMinimumDifference(TreeNode* root) {
        fun(root);
        sort(v1.begin(),v1.end());
        for(int i=1;i<v1.size();i++){
            min1=min(min1,v1[i]-v1[i-1]);
        }
        return min1;
        
    }
};