class Solution {
public:
   void fun(vector<vector<char>> &g,vector<vector<int>> &vis,int i,int j){

        queue<pair<int,int>> q;
        q.push({i,j});
      vis[i][j]=1;
        while(!q.empty()){
            auto [x,y]=q.front();
            
            q.pop();
            if(x-1>=0 && g[x-1][y]=='1' && vis[x-1][y]!=1){
                q.push({x-1,y});
                vis[x-1][y]=1;

            }
            if(y-1>=0 && g[x][y-1]=='1' && vis[x][y-1]!=1){
   q.push({x,y-1});
   vis[x][y-1]=1;
            }
            if(x+1<g.size() && g[x+1][y]=='1' && vis[x+1][y]!=1){
                   q.push({x+1,y});
                   vis[x+1][y]=1;

            }
            if(y+1<g[0].size() && g[x][y+1]=='1' && vis[x][y+1]!=1){
                   q.push({x,y+1});
                   vis[x][y+1]=1;

            }

        }
    }
    int numIslands(vector<vector<char>>& g) {
        int c=0;
        vector<vector<int>> vis(g.size(),vector<int>(g[0].size(),0));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]=='1' && vis[i][j]==0){
                    c++;
                    fun(g,vis,i,j);

                }
            }
        }
        return c;
        
    }
};