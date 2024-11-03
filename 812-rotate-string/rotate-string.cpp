class Solution {
public:
    bool rotateString(string s, string g) {
        int x=100;
        while(x--){
            if(s==g){
                return true;
            }
            string z="";
            z+=s[0];
            s=s.substr(1,s.size());
            s+=z;


        }
 return false;       
    }
};