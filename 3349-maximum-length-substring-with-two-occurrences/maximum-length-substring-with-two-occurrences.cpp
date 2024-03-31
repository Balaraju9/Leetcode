class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0,max1=0,max2=0;
        unordered_map<char,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            max1=max(max1,mp[s[j]]);
            while(max1>2){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);

                }
                max1=min(max1,mp[s[j]]);
                i++;
            }
            max2=max(max2,(j-i)+1);
            j++;
        }
        return max2;

        
    }
};