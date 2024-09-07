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
    vector<int> v2;
    void fun(TreeNode* root1){
        if(root1==NULL){
            return;
        }
        if(root1->left==NULL && root1->right==NULL){
            v1.push_back(root1->val);
        }
        fun(root1->left);
        fun(root1->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        fun(root1);
        v2=v1;
        v1.clear();
        fun(root2);
        return v1==v2;
        
    }
};