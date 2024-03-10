class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        vector<int>v1;
        unordered_map<int,int> mp;
        for(int i=0;i<n1.size();i++){
            mp[n1[i]]++;
        }
        for(int i=0;i<n2.size();i++){
            if(mp.find(n2[i])!=mp.end() && mp[n2[i]]!=-978){
                v1.push_back(n2[i]);
                mp[n2[i]]=-978;
            }
        }
        return v1;

        
    }
};