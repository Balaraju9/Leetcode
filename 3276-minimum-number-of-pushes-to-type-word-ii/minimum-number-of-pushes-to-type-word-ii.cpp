class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v1;
        unordered_map<int,int> mp;
        for(auto &i:word){
            mp[i]++;
        }
        for(auto &i:mp){
            v1.push_back(i.second);
        }
       sort(v1.begin(),v1.end());
       int c=1;
       int z=0,pu=0;
        for(int i=v1.size()-1;i>=0;i--){
            if(z==8){
                c++;
                z=0;

            }
            pu+=(c*v1[i]);
            z++;
        }
        return pu;
        
    }
};