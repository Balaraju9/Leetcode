class Solution {
public:
    int maxFrequencyElements(vector<int>& n) {
        int c=0,max1=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n.size();i++){
            mp[n[i]]++;
            max1=max(max1,mp[n[i]]);
        }
        for(auto &i:mp){
            if(i.second==max1){
                c=c+i.second;
            }
        }
        return c;
    }
};