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
    TreeNode* r1;
    TreeNode* r2=r1;

    void fun(TreeNode* r){
        if(r==NULL){
            return;
        }
        v1.push_back(r->val);
        fun(r->left);
        fun(r->right);
    }
    void fun1(vector<int> v1,int i){
       for(int i=1;i<v1.size();i++){
        TreeNode* k=new TreeNode(v1[i]);
        r2->right=k;
        r2=r2->right;

       }

    }
    TreeNode* increasingBST(TreeNode* r) {
        fun(r);
        sort(v1.begin(),v1.end());
        r1=new TreeNode(v1[0]);
        r2=r1;
        fun1(v1,0);
        return r1;
        
        
    }
};