class Solution {
public:
    int minBitFlips(int st, int g) {
        string s1=bitset<128>(st).to_string();
        string s2=bitset<128>(g).to_string();
        int c=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                c++;
            }
        }
        return c;
        
    }
};