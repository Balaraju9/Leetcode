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
vector<int> v1,v2;
void fun(TreeNode *p,vector<int> &v1){
    if(p==NULL){
        return;
    }
    v1.push_back(p->val*9);
    fun(p->left,v1);
    v1.push_back(p->val*10);
    fun(p->right,v1);

}
void fun1(TreeNode *q,vector<int> &v2){
      if(q==NULL){
        return;
    }
    v2.push_back(q->val*9);
    fun(q->left,v2);
    v2.push_back(q->val*10);
    fun(q->right,v2);

    
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        fun(p,v1);
        fun1(q,v2);
        return v1==v2;
        
    }
};