class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        for(int i=c.size()-3;i>=0;i--){
            c[i]=c[i]+min(c[i+1],c[i+2]);
        }
        return min(c[0],c[1]);
        
    }
};