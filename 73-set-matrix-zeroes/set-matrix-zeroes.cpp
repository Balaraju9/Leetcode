class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        unordered_map<int,int> mp;
         unordered_map<int,int> mp1;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(m[i][j]==0){
                    mp[i]++;
                    mp1[j]++;
                }
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(mp.find(i)!=mp.end() || mp1.find(j)!=mp1.end()){
                    m[i][j]=0;
                }
            }
        }
        
        
    }
};