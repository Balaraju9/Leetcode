class Solution {
public:
    void fun(int ind,vector<int> &vis,vector<vector<int>> v1){
        vis[ind]=true;
        for(auto &i:v1[ind]){
            if(vis[i]==false){
                fun(i,vis,v1);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        vector<vector<int>> v1(c.size());
        for(int i=0;i<c.size();i++){
            for(int j=0;j<c[i].size();j++){
                if(c[i][j]==1 && i!=j){
                v1[i].push_back(j);
                v1[j].push_back(i);
            }
            }
        }
       vector<int> vis(c.size(),false);
       int c1=0;
       for(int i=0;i<vis.size();i++){
        if(vis[i]==false){
            c1++;
            fun(i,vis,v1);
        }
       }
        return c1;
    }
};