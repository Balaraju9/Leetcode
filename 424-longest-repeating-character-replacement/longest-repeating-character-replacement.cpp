class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, max1 = 0, max2 = 0;
        unordered_map<char, int> mp;
        while (j < s.size()) {
            mp[s[j]]++;

            max1 = max(max1, mp[s[j]]);
            if ((j - i + 1) - max1 <= k) {
                max2 = max(max2, (j - i) + 1);
            } else {
                while ((j - i + 1) - max1 > k) {

                    mp[s[i]]--;
                    i++;
                   
                }
            }
            j++;
        }
        return max2;
    }
};