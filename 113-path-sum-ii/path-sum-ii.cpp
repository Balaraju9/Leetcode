/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v2;
    vector<vector<int>> v1;
    void fun(TreeNode* root, int t) {

        if (root != NULL && root->right == NULL && root->left == NULL &&
            t - root->val == 0) {
            v2.push_back(root->val);
            v1.push_back(v2);
            v2.pop_back();
            return;

        }
        else if(root!=NULL && root->right==NULL && root->left==NULL){
           
            return;
        }

        else if (root == NULL) {
            return;
        }
        v2.push_back(root->val);
        fun(root->left, t - root->val);
      
        fun(root->right, t - root->val);
         v2.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        fun(root, t);
        return v1;
    }
};