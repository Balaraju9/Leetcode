class Solution {
public:
    int firstMissingPositive(vector<int>& n) {
        map<int,int> mp;
        
        for(int i=1;i<=n.size();i++){
            mp[i]++;
        }
        for(auto &i:n){
            mp[i]--;
        }
        for(auto &i:mp){
            if(i.second==1){
                return i.first;
            }
        }
        return n.size()+1;
        
    }
};