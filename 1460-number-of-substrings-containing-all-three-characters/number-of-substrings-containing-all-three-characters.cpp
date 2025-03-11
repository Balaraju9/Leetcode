class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()==3){
                ans+=(s.size()-j);
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
        
    }
};