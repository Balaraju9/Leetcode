/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* balu;
    int n,m;
    void fun(vector<vector<int>> &v1, int i, int j, char pu) {
        if (balu == NULL) {
            return;
        }
        if (pu == 'r'  ) {
            if (i>=0 && j>=0 && i < m && j < n && v1[i][j] == 139916811) {
                v1[i][j] = balu->val;
                balu = balu->next;
                fun(v1, i, j + 1, pu);

            } else {
                fun(v1, i + 1, j - 1, 'd');
            }
        }
         else if (pu == 'd' ) {
            if (i>=0 && j>=0 && i < m && j < n && v1[i][j] == 139916811) {
                v1[i][j] = balu->val;
                balu = balu->next;
                fun(v1, i + 1, j, pu);

            } else {
                fun(v1, i - 1, j - 1, 'l');
            }
        } else if (pu == 'l') {
            if (i>=0 && j>=0 && i < m && j < n && v1[i][j] == 139916811) {
                v1[i][j] = balu->val;
                balu = balu->next;
                fun(v1, i, j - 1, pu);

            } else {
                fun(v1, i - 1, j + 1, 't');
            }
        } else if(pu=='t'){
            if (i>=0 && j>=0 && i < m && j < n && v1[i][j] == 139916811) {
                v1[i][j] = balu->val;
                balu = balu->next;
                fun(v1, i - 1, j, pu);

            } else {
                fun(v1, i+1, j + 1, 'r');
            }
        }
    }
    vector<vector<int>> spiralMatrix(int m1, int n1, ListNode* h) {
        balu = h;
        m=m1;
        n=n1;
        vector<vector<int>> vec(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec[i][j] = 139916811;
            }
        }
        fun(vec, 0, 0, 'r');
          for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(vec[i][j] == 139916811){
                    vec[i][j]=-1;                    
                }
            }
        }
        return vec;
    }
};
// 139916811