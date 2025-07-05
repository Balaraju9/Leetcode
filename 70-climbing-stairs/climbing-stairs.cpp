class Solution {
public:
    int climbStairs(int n) {
        vector<int> v1(n+1);
        v1[0]=1;
        v1[1]=2;
        for(int i=2;i<n;i++){
            v1[i]=v1[i-1]+v1[i-2];
        }
        
        return v1[n-1];
    }
};