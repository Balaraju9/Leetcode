class Solution {
public:
    char findTheDifference(string s, string t) {
        int s1=0;
       for(int i=0;i<s.size();i++){
       
        s1=s1^int(s[i]);
       }
       for(int j=0;j<t.size();j++){
       
        s1=s1^int(t[j]);
        
       }
    
       return char(s1);
    }
};