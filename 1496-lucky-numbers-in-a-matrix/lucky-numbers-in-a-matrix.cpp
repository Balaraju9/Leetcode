class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        vector<vector<int>> v1;
        int j=0;
        int min1=INT_MAX,ind;
        for(int i=0;i<m.size();i++){
            min1=INT_MAX,ind=0;
            for(int j=0;j<m[i].size();j++){
                if(min1>m[i][j]){
                    min1=min(min1,m[i][j]);
                    ind=j;
                }
            }
            v1.push_back({min1,ind});


        }
        vector<int> v2;
        for(int i=0;i<v1.size();i++){
            int k=v1[i][0];
            int k1=v1[i][1];
            for(int j=0;j<m.size();j++){

                if(m[j][k1]<=k){
                    if(j==m.size()-1){
                        v2.push_back(k);
                    }
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return v2;
    }
};