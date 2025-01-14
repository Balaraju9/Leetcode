class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mp;
        vector<int> ans(a.size());
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
            mp[b[i]]++;
            ans[i]=((i+1)*2)-mp.size();
        }
        return ans;
        
    }
};