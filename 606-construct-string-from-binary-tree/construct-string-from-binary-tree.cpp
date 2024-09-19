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
    string fun(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        if (root->left == NULL && root->right == NULL) {
            return to_string(root->val) ;
        }
        string l = "(" + tree2str(root->left) + ")";
        if (root != NULL && root->right != NULL) {
              string r = "(" + fun(root->right) + ")";
            return to_string(root->val) + l + r;
        }
        return to_string(root->val) + l ;
    }
    string tree2str(TreeNode* root) { return fun(root); }
};