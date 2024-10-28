class Solution {
public:
    int longestSquareStreak(vector<int>& n) {
        long long int max1 = 0;
        for(int i = 0; i < n.size(); i++) {
           if(max1 < n[i]) {
               max1 = n[i];
           }
        }

        unordered_map<long long int, long long int> mp;
        for(int i = 0; i < n.size(); i++) {
            mp[n[i]]++;
        }

        int ans = -1;
        for(int i = 0; i < n.size(); i++) {
            if(max1 >= static_cast<long long>(n[i]) *static_cast<long long>(n[i]) && mp.find(static_cast<long long>(n[i]) * static_cast<long long>(n[i])) != mp.end()) {
                int c = 0;
                long long k = static_cast<long long>(n[i]) * static_cast<long long>(n[i]);
                while(mp.find(k) != mp.end()) {
                    c++;
                    k = k * k;
                }
                ans = max(ans, c + 1);
            }
        }
        return ans;
    }
};
