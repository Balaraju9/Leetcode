class Solution {
public:
    int minDistance(string w1, string w2) {
        int min1=9999;
        vector<vector<int>> v1(w1.size()+1,vector<int>(w2.size()+1,0));
        for(int i=0;i<=w1.size();i++){
            v1[i][0]=i;

        }
        for(int i=0;i<=w2.size();i++){
            v1[0][i]=i;
        }
      for(int i=1;i<v1.size();i++){
        for(int j=1;j<v1[i].size();j++){
            if(w1[i-1]==w2[j-1]){
                v1[i][j]=v1[i-1][j-1];
            }
            else{
                min1=min(v1[i-1][j],v1[i][j-1]);
                min1=min(min1,v1[i-1][j-1]);
                v1[i][j]=1+min1;
            }

        }
      }
      return v1[w1.size()][w2.size()];
        return 3;

        
    }
};