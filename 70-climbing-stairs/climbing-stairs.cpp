class Solution {
public:
    int fun(int n, vector<int>& v1) {  // Pass v1 by reference
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return 0;
        }
        if (v1[n] != -1) return v1[n];

        int l = fun(n - 1, v1);
        int r = fun(n - 2, v1);
        v1[n] = l + r;
        return l + r;
    }
    
    int climbStairs(int n) {
        vector<int> v1(50, -1);  // Initialize the vector
        return fun(n, v1);
    }
};
