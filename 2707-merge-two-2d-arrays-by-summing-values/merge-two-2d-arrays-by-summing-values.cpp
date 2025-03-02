class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
        map<int,int> mp;
        for(int i=0;i<n1.size();i++){
            mp[n1[i][0]]=n1[i][1];
        }
        for(int i=0;i<n2.size();i++){
            mp[n2[i][0]]=mp[n2[i][0]]+n2[i][1];
        }
        vector<int> v1;
        n1.clear();
        for(auto &i:mp){
            v1.push_back(i.first);
            v1.push_back(i.second);
            n1.push_back(v1);
            v1={};
        }
        return n1;

        
    }
};