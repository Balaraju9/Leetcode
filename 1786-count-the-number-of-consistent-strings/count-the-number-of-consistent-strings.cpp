class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) {
        unordered_map<char,int> mp;
        for(auto &i:a){
            mp[i]++;
        }
        unordered_map<char,int> mp1=mp;
        int k=mp.size();
        int z=0;
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w[i].size();j++){
                mp1[w[i][j]]++;
                if(mp1.size()>k){
                    z++;
                    break;
                }


            }
            mp1=mp;
        }
        return w.size()-z;
        
    }
};