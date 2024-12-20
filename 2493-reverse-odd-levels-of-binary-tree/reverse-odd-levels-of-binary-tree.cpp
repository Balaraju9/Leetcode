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
 void fun1(TreeNode* r, int le, map<int, vector<int>>& mp) {
        if (r == NULL) {
            return;
        }
        if (le % 2 != 0) {
            vector<int> v1=mp[le];
          
            r->val=v1[v1.size()-1];
           
            mp[le].pop_back();
            
        }
        fun1(r->right, le + 1, mp);
        fun1(r->left, le + 1, mp);
    }
    void fun(TreeNode* r, int le, map<int, vector<int>>& mp) {
        if (r == NULL) {
            return;
        }
        if (le % 2 != 0) {
            mp[le].push_back(r->val);
        }
        fun(r->left, le + 1, mp);
        fun(r->right, le + 1, mp);
    }
    TreeNode* reverseOddLevels(TreeNode* r) {
        map<int, vector<int>> mp;

        fun(r, 0, mp);
       

        for (auto& i : mp) {
           
            vector<int> v2 = i.second;
            reverse(v2.begin(),v2.end());
            i.second=v2;

           
        }
       
         fun1(r,0,mp);
        return r;
    }
};