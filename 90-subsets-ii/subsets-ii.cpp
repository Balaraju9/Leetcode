class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& n) {
        map<vector<int>,int> mp;
        vector<vector<int>> v2;
        vector<int> v1;
        for(int i=0;i<pow(2,n.size());i++){
            for(int j=0;j<n.size();j++){
                if(i&(1<<j)){
                    v1.push_back(n[j]);
                }
            }
            sort(v1.begin(),v1.end());
            mp[v1]++;
            v1.clear();
        }
        for(auto &i:mp){
           v2.push_back(i.first);
        }
        return v2;
        
    }
};