class Solution {

public:
    string ans;
    void fun(int n, int &k, string s1, stack<char> &st) {
        if (st.size() == n || k == 0) {
            k--;
            if (k == 0) {
                while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
            }
            return;
        }
        for (int i = 0; i < s1.size(); i++) {
          if (st.empty() ||st.top() != s1[i])  {
                st.push(s1[i]);
                fun(n, k, s1, st);
                if (!st.empty()) {
                    st.pop();
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        stack<char> st;
        fun(n, k, "abc", st);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};