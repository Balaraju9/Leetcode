class Solution {
public:
    int minBitFlips(int s, int g) {
        string k=bitset<128>(s).to_string();
        string k1=bitset<128>(g).to_string();
        int i=k.size()-1,j=k1.size()-1;
        int ans=0;
       while(i>=0 && j>=0){
        ans+=(abs((k[i]-'0')-(k1[i]-'0')));
        i--;
        j--;

       }
       return ans;
        
    }
};