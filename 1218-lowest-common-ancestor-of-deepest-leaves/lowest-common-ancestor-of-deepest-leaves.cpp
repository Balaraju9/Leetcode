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
    int max1=0;
    TreeNode* p1=NULL;
    TreeNode* p2=NULL;
    void fun1(TreeNode* r,int c){
        if(r==NULL){
            return;
        }
      
        if(max1==c){
            if(p1==NULL){
                p1=r;

            }
            if(p1!=NULL){
                p2=r;
            }
        }
        fun1(r->left, c+1);
        fun1(r->right, c+1);
    }
    void fun(TreeNode* r,int c){
        if(r==NULL){
            return;
        }
        max1=max(max1,c);
        fun(r->left,c+1);
        fun(r->right,c+1);
    }
        void fun2(TreeNode* r,unordered_map<TreeNode*,TreeNode*> &mp){
        if(r==NULL){
            return;
        }
        if(r->left!=NULL){
            mp[r->left]=r;
        }
        if(r->right!=NULL){
            mp[r->right]=r;
        }
     
        fun2(r->left,mp);
        fun2(r->right,mp);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* r) {
        fun(r,0);
       
        fun1(r,0);
         unordered_map<TreeNode*,TreeNode*> mp;
          unordered_map<TreeNode*,int> mp1;
        fun2(r,mp);
        if(p1==p2)return p1;
        while(p1!=NULL){
            mp1[mp[p1]]++;
            p1=mp[p1];
        }
        while(p2!=NULL){
            if(mp1.find(p2)!=mp1.end()){
                return p2;
            }
            p2=mp[p2];
        }
        return p2;
        
    }
};