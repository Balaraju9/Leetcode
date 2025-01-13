class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        int c=0;
        for(auto &i:s){
            mp[i]++;
        }
        for(auto &i:mp){
            if(i.second&1){
                c+=1;
            }
            else c+=2;
        }
        return c;
    }
};