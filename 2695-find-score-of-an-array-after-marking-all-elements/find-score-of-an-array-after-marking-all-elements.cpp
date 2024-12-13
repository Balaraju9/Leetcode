class Solution {
public:
    long long findScore(vector<int>& n) {
        vector<pair<long long int,long long int>> v1;
        for(long long int i=0;i<n.size();i++){
            v1.push_back({n[i],i});
        }
        sort(v1.begin(),v1.end());
        unordered_map<long long int,long long int> mp;
        long long int s=0;
        for(auto &i:v1){
            if(!mp[i.second]>=1){
                s+=i.first;
                mp[i.second]++;
                mp[i.second-1]++;
                mp[i.second+1]++;


            }
        }
        return s;
        
    }
};