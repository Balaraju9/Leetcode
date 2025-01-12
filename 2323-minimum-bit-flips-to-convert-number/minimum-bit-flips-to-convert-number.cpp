class Solution {
public:
    int minBitFlips(int s, int g) {
        int pu=s^g;
        return __builtin_popcount(pu);
        
        
    }
};