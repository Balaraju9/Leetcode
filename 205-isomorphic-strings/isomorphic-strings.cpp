class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        string s1="",s2="";
        int c=0;
        unordered_map<char,char> mp1;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=t[i];
            mp1[t[i]]=s[i];
        }
 for(int i=0;i<s.size();i++){
           s1+=mp[s[i]];
           s2+=mp1[t[i]];
        }
        if(s2==s && s1==t){
            return true;
        }

       
        return false;

        
    }
};