class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<pair<int,int>,int>> q;
        int max1=0;
       for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            if(g[i][j]==2){
                q.push({{i,j},0});
            }
        }
       }
       while(!q.empty()){
        auto i1=q.front();
        q.pop();
        int i=i1.first.first;
        int j=i1.first.second;
        int c=i1.second;
        max1=max(max1,c);
        if(i+1<g.size() && g[i+1][j]==1){
            q.push({{i+1,j},c+1});
            g[i+1][j]=2;


        }
        if(i-1>=0 && g[i-1][j]==1){
             q.push({{i-1,j},c+1});
             g[i-1][j]=2;

        }
           if(j+1<g[i].size() && g[i][j+1]==1){
             q.push({{i,j+1},c+1});
              g[i][j+1]=2;

        }
        if(j-1>=0 && g[i][j-1]==1){
             q.push({{i,j-1},c+1});
             g[i][j-1]=2;

        }
        

       }
         for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            if(g[i][j]==1){
                return -1;
            }
        }
       }
        return max1;
        
    }
};