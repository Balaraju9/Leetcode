class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& n) {
        vector<vector<int>> v2;
        vector<int> v1;
        int max1=0;
        unordered_map<int,int> mp;
        for(auto &i:n){
            mp[i]++;
            max1=max(max1,mp[i]);
        }
        for(int j=1;j<=max1;j++){
            for(auto &i:mp){
                if(j<=i.second){
                    v1.push_back(i.first);
                }
            }
            v2.push_back(v1);
            v1.clear();
        }
        
        return v2;
    }
};
