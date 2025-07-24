class Solution {
public:
    bool fun(int i,int j,int i1,vector<vector<bool>> &vis,vector<vector<char>> &b,string &w){
        if(i1>=w.size()){
            return true;
        }
        if(i>=b.size() || j>=b[i].size() || vis[i][j]==true || w[i1]!=b[i][j] ){
            return false;
        }
        


        vis[i][j]=true;
        bool sul=fun(i+1,j,i1+1,vis,b,w) ||
                fun(i-1,j,i1+1,vis,b,w) ||
                fun(i,j+1,i1+1,vis,b,w) ||
                fun(i,j-1,i1+1,vis,b,w);
        vis[i][j]=false;
        return sul;

    }
    bool exist(vector<vector<char>>& b, string w) {
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                if(b[i][j]==w[0]){
                   vector<vector<bool>> vis(b.size(), vector<bool>(b[0].size(), false));
                      bool pu=fun(i,j,0,vis,b,w);
                      if(pu) return true;
                }
            }
        }
        return false;
        
    }
};