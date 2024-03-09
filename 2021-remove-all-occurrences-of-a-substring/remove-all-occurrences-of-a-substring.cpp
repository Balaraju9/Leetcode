class Solution {
public:
    string removeOccurrences(string s, string p) {
        while(s.find(p)!=string::npos){
            int z=s.find(p);
            s.erase(z,p.size());
        }
        return s;
        
    }
};