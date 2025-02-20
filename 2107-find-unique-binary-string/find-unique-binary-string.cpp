class Solution {
public:
    string findDifferentBinaryString(vector<string>& n) {
        int si=n.size();
        unordered_map<string,int> mp;
        for(int i=0;i<pow(2,si);i++){
            string pu;
            for(int j=0;j<si;j++){
                if(i&1<<j){
                    pu+='1';
                }
                else{
                    pu+='0';
                }
            }
            mp[pu]++;
        }
       for(auto &i:n){
        mp[i]--;
       }
       for(auto &i:mp){
        if(i.second>=1){
            return i.first;
        }
       }
        return "22";
        
    }
};