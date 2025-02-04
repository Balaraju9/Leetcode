class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        vector<vector<int>> vis(w.size(),vector<int>(w[0].size(),0));
          vector<vector<int>> dis(w.size(),vector<int>(w[0].size(),0));
          queue<pair<int,pair<int,int>>> q;
          for(int i=0;i<w.size();i++){
            for(int j=0;j<w[i].size();j++){
                if(w[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
          }
          while(!q.empty()){
            auto pu=q.front();
            q.pop();

            int c=pu.first;
            int i=pu.second.first;
            int j=pu.second.second;
            dis[i][j]=c;
            if(i+1<w.size() && vis[i+1][j]!=1){
                q.push({c+1,{i+1,j}});
                vis[i+1][j]=1;
            }
             if(i-1>=0 && vis[i-1][j]!=1){
                q.push({c+1,{i-1,j}});
                vis[i-1][j]=1;
            }
             if(j+1<w[i].size() && vis[i][j+1]!=1){
                q.push({c+1,{i,j+1}});
                vis[i][j+1]=1;
            }
             if(j-1>=0 && vis[i][j-1]!=1){
                q.push({c+1,{i,j-1}});
                vis[i][j-1]=1;
            }

          }

          return dis;

        
    }
};