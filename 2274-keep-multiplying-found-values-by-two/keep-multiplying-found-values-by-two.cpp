class Solution {
public:
    int findFinalValue(vector<int>& n, int oer) {
        unordered_map<int,int> mp;
        for(auto &i:n){
            mp[i]++;
        }
        while(mp.find(oer)!=mp.end()){
            oer=oer*2;
        }
        return oer;
        
    }
};