class Solution {
public:
    string fun(string s,int k){
        string s1="";
        for(int i=0;i<s.size();i++){
            int t=(i+k)%s.size();
            s1+=s[t];
            
        }
        return s1;
    }
    bool rotateString(string s, string g) {
        for(int i=0;i<s.size();i++){
            if(fun(s,i)==g){
                return true;
            }
        }
        return false;
        
    }
};