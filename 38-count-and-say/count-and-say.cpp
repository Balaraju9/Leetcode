class Solution {
public:
    string countAndSay(int n) {
        string s1 = "1";
        string s2;
        int c = 0;
        while (--n) {
            for (int i = 0; i < s1.size();) {
                char k = s1[i];
                while (i < s1.size() && s1[i] == k) {
                    i++;
                    c++;
                }
                s2 += to_string(c) + k;
                c = 0;
            }

            c = 0;
            s1 = s2;
            s2 = "";
        }
        return s1;
    }
};