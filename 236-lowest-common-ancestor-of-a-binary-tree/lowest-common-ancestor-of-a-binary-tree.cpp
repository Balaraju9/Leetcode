/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  
    void fun(TreeNode* r,unordered_map<TreeNode*,TreeNode*> &mp){
        if(r==NULL){
            return;
        }
        if(r->left!=NULL){
            mp[r->left]=r;
        }
        if(r->right!=NULL){
            mp[r->right]=r;
        }
     
        fun(r->left,mp);
        fun(r->right,mp);
    }
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*> mp;
        fun(r,mp);
         unordered_map<TreeNode*,int> mp1;
       while (p != NULL) {
   mp1[p]++;
    p = mp[p];
}
      while (q != NULL) {
  if(mp1.find(q)!=mp1.end()){
    return q;
  }
    q = mp[q];
}

//        for (auto &i : mp1) {
//     if (i.first)  
//         cout << i.first->val << " ";
//     else
//         cout << "NULL ";
// }

        // for(auto &i:mp){
        //     if(i.first==p){cout<<"Pud";}
        //     cout<<i.first->val<<" "<<i.second->val<<"\n";
        // }
        return p;
        
    }
};