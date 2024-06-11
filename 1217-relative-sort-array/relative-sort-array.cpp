class Solution {
public:
    vector<int> relativeSortArray(vector<int>& ar1, vector<int>& ar2) {
        map<int,int> mp;
        for(auto &i:ar1){
            mp[i]++;
        }
        int  k=0;
        vector<int> v1;
        for(int i=0;i<ar2.size();i++){
            k=mp[ar2[i]];
            while(k>0){
                v1.push_back(ar2[i]);
                mp[ar2[i]]--;
                k--;

            }
        }
        for(auto &i:mp){
            while(i.second>0){
                v1.push_back(i.first);
                i.second--;
            }
        }
        return v1;
        
    }
};