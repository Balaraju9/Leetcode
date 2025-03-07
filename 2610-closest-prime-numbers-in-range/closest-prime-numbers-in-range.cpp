class Solution {
public:
    vector<int> closestPrimes(int l, int r) {

        vector<bool> v1(r + 1, true);
        v1[0] = false;
        v1[1] = false;
        for (long long int i = 2; i < r + 1; i++) {
            if (v1[i] == true) {
                for (long long int j = i * i; j < r + 1; j = j + i) {
                    v1[j] = false;
                }
            }
        }
        vector<int> v2;
        int pu = -1,min1=INT_MAX;
        vector<int> ans(2,-1);
        for (int i = v1.size() - 1; i >= 0; i--) {
            if (v1[i] == true && i >= l) {
                if (pu != -1) {
                    if (min1 >= pu - i) {
                        ans[0] = i;
                        ans[1] = pu;
                        min1 = pu - i;
                    }

                    pu = i;
                } else {
                    pu = i;
                }
            }
        }

        return ans;
    }
};