class Solution {
public:
    int coinChange(vector<int>& c, int t) {
        vector<vector<int>> v1(c.size()+1,vector<int>(t+1,0));
        for(int i=0;i<v1.size();i++){
            v1[i][0]=0;
        }
        for(int i=0;i<t+1;i++){
            v1[0][i]=INT_MAX-1;
        }
        for(int i=1;i<v1.size();i++){
            for(int j=1;j<v1[i].size();j++){
                if(c[i-1]<j){
                    int pu=j-c[i-1];
                    v1[i][j]=min(1+v1[i][pu],v1[i-1][j]);

                }
                else if(c[i-1]==j){
                    v1[i][j]=1;
                }
                else{
                    v1[i][j]=v1[i-1][j];
                }

               

            }
           
        }
        if(v1[v1.size()-1][v1[0].size()-1]<=pow(10,4)){
              return v1[v1.size()-1][v1[0].size()-1];
        }
        return -1;



      
        
    }
};