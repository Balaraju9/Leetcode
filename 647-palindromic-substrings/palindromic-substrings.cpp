class Solution {
public:
    int countSubstrings(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            int i1=i-1;
            int j1=i+1;
            while(i1>=0 && j1<s.size() && s[i1]==s[j1]){
                i1--;
                j1++;
                c++;
            }
            
        }
             for(int i=0;i<s.size();i++){
            int i1=i-1;
            int j1=i;
            while(i1>=0 && j1<s.size() && s[i1]==s[j1]){
                i1--;
                j1++;
                c++;
            }
            
        }
        
        return c+s.size();
        
    }
};