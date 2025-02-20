class Solution {
public:
    string findDifferentBinaryString(vector<string>& n) {
        int si=n.size();
        unordered_map<string,int> mp;
        for(auto &i:n){
            mp[i]++;
        }
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
            if(!mp[pu]>=1){
                return pu;
            }
            
        }
     
        return "22";
        
    }
};