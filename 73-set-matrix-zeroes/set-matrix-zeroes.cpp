class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    v1.push_back(j);
                    v2.push_back(i);
                }
            }
        }
       for(int i=0;i<m.size();i++){
           for(int j=0;j<v1.size();j++){
               m[i][v1[j]]=0;
           }
       }
       for(int i=0;i<m[0].size();i++){
           for(int j=0;j<v2.size();j++){
               m[v2[j]][i]=0;
           }
       }
        
       
        
    }
};