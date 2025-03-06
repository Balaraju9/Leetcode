class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        int pu=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                int k=abs(g[i][j]);
                int i1=(k-1)/g.size();
                int j1=(k-1)%g.size();
                if(g[i1][j1]<0){
                    pu=abs(g[i][j]);

                }
                else{
                    g[i1][j1]=-1*g[i1][j1];
                }
            }
        }
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                if(g[i][j]>0){
                    vector<int> v1={pu,  static_cast<int>(i*g.size())+(j+1)};

                    return v1; 

                }
            }
        }
        return {};

        
    }
};