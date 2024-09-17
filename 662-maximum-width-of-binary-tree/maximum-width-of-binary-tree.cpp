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
    void fun(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            root->left->val = (long long)(2 * (long long)root->val) + 1;
        }
        if (root->right != NULL) {
            root->right->val = (long long)(2 *(long long) root->val) + 2;
        }
        fun(root->left);
        fun(root->right);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        if (root != NULL) {
            root->val = 0;
        }
        else{
            return 0;
        }
        int max1 = 1;
        fun(root);
        queue<TreeNode*> q;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {

            while (!q1.empty()) {
                TreeNode* balu = q1.front();
                q1.pop();
                if (balu->left != NULL) {
                    q.push(balu->left);
                }
                if (balu->right != NULL) {
                    q.push(balu->right);
                }
            }
            q1=q;
            if(q1.empty()){
                break;
            }
           int z = q1.size();
        int a = q1.front()->val;  // leftmost
        int b = q1.back()->val;   // rightmost
        max1 = max(max1, abs(a - b) + 1);  // Calculate width

        while (!q.empty()) {
            q.pop();  // Clear for next level
        }
        }

        return max1;
    }
};