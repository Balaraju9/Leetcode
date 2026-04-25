class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,max1=0;
        unordered_map<char,int> mp;
        while(j<s.size()){
                        mp[s[j]]++;

            if(mp[s[j]]<=1){
                max1=max(max1,(j-i)+1);
            }
            else{
                while(i<j && mp[s[j]]>1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                                        i++;

                }
            }
            j++;
        }
        return max1;
        
    }
};