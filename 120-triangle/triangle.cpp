class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        for(int i=tr.size()-2;i>=0;i--){
            for(int j=0;j<tr[i].size();j++){
                int k=min(tr[i+1][j],tr[i+1][j+1]);
                tr[i][j]=k+tr[i][j];
            }


        }
        return tr[0][0];
        
    }
};