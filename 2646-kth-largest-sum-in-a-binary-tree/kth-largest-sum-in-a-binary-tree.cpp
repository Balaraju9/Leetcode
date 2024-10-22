/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, long long int k) {
        if (root == NULL) {
            return -1;
        }
        queue<TreeNode*> st;
        st.push(root);
        long long int c1 = 0;
        vector<long long int> v3;
        v3.push_back(root->val);
        
        while (!st.empty()) {

            queue<TreeNode*> st1;
            while (!st.empty()) {
                TreeNode* k1 = st.front();
                
                st.pop();
                if (k1->left != NULL) {
                    st1.push(k1->left);
                    c1 += k1->left->val;
                }
                if (k1->right != NULL) {
                    st1.push(k1->right);
                    c1 += k1->right->val;
                }
            }
            st = st1;
            v3.push_back(c1);
            c1 = 0;
        }
        sort(v3.begin(),v3.end());
        reverse(v3.begin(),v3.end());
        for(auto &i:v3){
            cout<<i<<" ";
        }
        v3[v3.size()-1]=-1;
        if(k>v3.size()){
            return -1;
        }
     

        return v3[k-1];
    }
};