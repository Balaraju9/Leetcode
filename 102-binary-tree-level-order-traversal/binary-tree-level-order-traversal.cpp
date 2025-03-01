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
    vector<vector<int>> levelOrder(TreeNode* r) {
        queue<TreeNode*> q;
        vector<vector<int>> v1;
        vector<int> v2;
        q.push(r);
        while(!q.empty() && q.front()!=NULL){
            queue<TreeNode*> q1;
            while(!q.empty() && q.front()!=NULL){
                if(q.front()->right!=NULL){
                q1.push(q.front()->right);
                }
                if(q.front()->left!=NULL){
                q1.push(q.front()->left);
                }
                v2.push_back(q.front()->val);
                q.pop();

            }
            reverse(v2.begin(),v2.end());
            v1.push_back(v2);
            v2={};
            q=q1;
            while(!q1.empty()){
                q1.pop();
            }

        }
        return v1;
        
    }
};