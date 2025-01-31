class Solution {
public:
    void fun(vector<vector<char>> g,vector<vector<char>> &vis,int i,int j){
        vis[i][j]='1';
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int i1=front.first;
            int j1=front.second;
            if(i1+1<g.size() && vis[i1+1][j1]!='1' && g[i1+1][j1]=='1'){
                q.push({i1+1,j1});
                vis[i1+1][j1]='1';
            }
             if(i1-1>=0 && vis[i1-1][j1]!='1' && g[i1-1][j1]=='1'){
                q.push({i1-1,j1});
                 vis[i1-1][j1]='1';
            }
             if(j1+1<g[i1].size() && vis[i1][j1+1]!='1' && g[i1][j1+1]=='1'){
                q.push({i1,j1+1});
                 vis[i1][j1+1]='1';
            }
             if(j1-1>=0 && vis[i1][j1-1]!='1' && g[i1][j1-1]=='1'){
                q.push({i1,j1-1});
                 vis[i1][j1-1]='1';
            }
           

        }

    }
    int numIslands(vector<vector<char>>& g) {
        vector<vector<char>> vis(g.size(), vector<char>(g[0].size(), '0'));
        int c=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]=='1' && vis[i][j]!='1'){
                    fun(g,vis,i,j);
                    c++;
                }
            }
        }
        return c;
        
    }
};