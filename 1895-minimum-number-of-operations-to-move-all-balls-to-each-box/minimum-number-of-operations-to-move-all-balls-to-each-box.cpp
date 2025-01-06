class Solution {
public:
    vector<int> minOperations(string b) {
        map<int,int> mp;
        for(int i=0;i<b.size();i++){
            if(b[i]=='1'){
                mp[i]=i;
            }
        }
        vector<int> v1(b.size());
        for(int i=0;i<b.size();i++){
            int c=0;
            for(auto &j:mp){
                if(j.first!=i){
                    c+=abs(j.second-i);

                }
            }
            v1[i]=c;

        }
        return v1;
        
    }
};