class Solution {
public:
    bool rotateString(string s, string g) {
        if(s.size()!=g.size()){
            return false;
        }
        s=s+s;
        if(s.find(g)!=string::npos){
            return true;
        }
        return false;

        
    }
};