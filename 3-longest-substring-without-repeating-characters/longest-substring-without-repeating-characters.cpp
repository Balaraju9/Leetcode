class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,max1=0;;
        unordered_map<char,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp[s[j]]>1 && j<s.size()){
                mp[s[i]]--;
                i++;
            }
            max1=max(max1,(j-i)+1);
            j++;

        }
        return max1;
        
    }
};