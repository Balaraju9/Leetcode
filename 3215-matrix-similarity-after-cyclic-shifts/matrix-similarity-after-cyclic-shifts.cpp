class Solution {
public:

    bool areSimilar(vector<vector<int>>& m, int k) {
        vector<vector<int>> m1=m;
        
      
            for(int i=0;i<m.size();i++){
                
                for(int j=0;j<m[0].size();j++){
            int t=(j+k)%m[0].size();
            m[i][j]=m[i][t];
        
                
            }
        }
        
        return m==m1;
        
    }
};