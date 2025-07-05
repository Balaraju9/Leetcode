class Solution {
public:
    int change(int a, vector<int>& c) {
        if(a==0) return 1;
         using ull = unsigned long long;
        vector<vector<ull>> v1(c.size() + 1, vector<ull>(a + 1, 0));
     
        for(long long int i=1;i<v1.size();i++){
            for(long long int j=1;j<v1[i].size();j++){
                long long int curn=c[i-1];
                if(curn<j){
                    long long int pu=j-curn;
                    v1[i][j]=(v1[i][pu]+v1[i-1][j] );

                }
                else if(curn==j){
                    v1[i][j]=1+v1[i-1][j];

                }
                else{
                    v1[i][j]=v1[i-1][j];

                }
            }
        }
        return v1[c.size()][a];
        
    }
};