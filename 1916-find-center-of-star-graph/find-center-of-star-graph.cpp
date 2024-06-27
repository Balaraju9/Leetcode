class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
      unordered_map<int,int> mp;
      for(int i=0;i<e.size();i++){
        for(int j=0;j<e[i].size();j++){
            mp[e[i][j]]++;
        }
      }
      for(auto &i:mp){
        if(i.second==e.size()){
            return i.first;
        }
      }
      return 0;
         
        
        
    }
};