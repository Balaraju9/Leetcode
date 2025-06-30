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
    bool sup=false;
    void fun1(TreeNode* r,TreeNode* s){
        if(r==NULL && s==NULL){
            return;
        }
        if(r==NULL){
            sup=false;
            return;
        }
        if(s==NULL){
            sup=false;
            return;
        }
        if(r->val != s->val){
            sup=false;
            return;
        }
        fun1(r->left,s->left);
        fun1(r->right,s->right);
    }
    void fun(TreeNode* r,TreeNode* s){
        if(r==NULL || sup==true){
            return;
        }
        if(r->val==s->val){
            sup=true;
            fun1(r,s);
            if(sup==true) return;

        }

        fun(r->left,s);
        fun(r->right,s);
    }
    bool isSubtree(TreeNode* r, TreeNode* s) {
        fun(r,s);
        return sup;
        
    }
};