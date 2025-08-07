class Solution {
public:
    int max2=1;
    int fun(vector<vector<int>>& m, int i, int j, vector<vector<int>>& vis,vector<vector<int>> &dp) {
        if(i>=m.size() || j>=m[0].size() || i<0 || j<0 || vis[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        vis[i][j]=1;
        // max1=max(max1,c);
        int r1=0,r2=0,c1=0,c2=0;
        if (i + 1 < m.size() && vis[i + 1][j] == 0 && m[i + 1][j] > m[i][j]) {
             r1=1+fun(m, i + 1, j, vis,dp);
        }
        if (i - 1 >= 0 && vis[i - 1][j] == 0 && m[i - 1][j] > m[i][j]) {
            r2=1+ fun(m, i - 1, j, vis,dp);
        }
        if (j + 1 < m[0].size() && vis[i][j + 1] == 0 &&
            m[i][j + 1] > m[i][j]) {
             c1=1+fun(m, i, j + 1, vis,dp);
        }
        if (j - 1 >= 0 && vis[i][j - 1] == 0 && m[i][j - 1] > m[i][j]) {
             c2=1+fun(m, i, j - 1, vis,dp);
        }
        vis[i][j]=0;
        int max1=max(r1,r2);
        max1=max(max1,c1);
        max1=max(max1,c2);
        dp[i][j]=max1;
        max2=max(max2,max1+1);
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& m) {
        vector<vector<int>> vis(m.size(), vector<int>(m[0].size()));
         vector<vector<int>> dp(m.size(), vector<int>(m[0].size(),-1));

        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                fun(m, i, j, vis,dp);
            }
        }
        return max2;
    }
};