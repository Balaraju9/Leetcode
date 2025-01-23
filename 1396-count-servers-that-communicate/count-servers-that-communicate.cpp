class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        vector<int> r(g.size());
        vector<int> c(g[0].size());
        int c1=0;
        for(int i=0;i<g.size();i++){
            c1=0;
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]==1){
                    r[i]++;
                     c[j]++;
                }
            }
           
        }
          for(auto &i:r){
        cout<<i<<" *";
      }
     
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]==1){
                if(r[i]>=2 || c[j]>=2){
                    g[i][j]=2;
                }
                }
            }
        }
        c1=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
             
                if(g[i][j]==2){
                    c1++;
                }
            }
            cout<<"\n";


        }
        return c1;
        
    }
};