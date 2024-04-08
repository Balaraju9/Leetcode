class Solution {
public:
    int countStudents(vector<int>& s1, vector<int>& s2) {
        unordered_map<int,int> mp;
        for(auto &i:s1){
            mp[i]++;

        }
        for(int i=0;i<s2.size();i++){
            if(mp.find(s2[i])!=mp.end()){
                mp[s2[i]]--;
                if(mp[s2[i]]==0){
                    mp.erase(s2[i]);
                }
            }
            else{
                break;
            }
        }
        int s4=0;
        for(auto &i:mp){
            s4+=i.second;
        }
        return s4;

        
    }
};