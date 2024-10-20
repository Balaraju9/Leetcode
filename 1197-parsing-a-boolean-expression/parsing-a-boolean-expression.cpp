class Solution {
public:
    char fun(char maya, string s1) {
        bool su;
        if (s1.size() == 1) {
            if (maya == '&' || maya=='|') {
                return s1[0];
            } else {
                if (s1[0] == 't') {
                    return 'f';
                } else {
                    return 't';
                }
            }

        } else {
            if (maya == '&') {
                su = s1[0] == 't' ? true : false;
                for (int i = 1; i < s1.size(); i++) {
                    bool su1 = s1[i] == 't' ? true : false;
                    su = su & su1;
                }
            } else if(maya=='|'){
                su = s1[0] == 't' ? true : false;
                for (int i = 1; i < s1.size(); i++) {
                    bool su1 = s1[i] == 't' ? true : false;
                    su = su | su1;
                }
            }
       
        }
        if (su == true) {
            return 't';
        }
        return 'f';
    }
    bool parseBoolExpr(string e) {
        stack<char> st;
        for (int i = 0; i < e.size(); i++) {
            if (e[i] == ')') {
                string s1 = "";
                while (!st.empty() && st.top() != '(') {
                    s1 += st.top();
                    st.pop();
                }
                st.pop();
                char maya = st.top();
                st.pop();

                st.push(fun(maya, s1));

            } else {
                if (e[i] != ',') {
                    st.push(e[i]);
                }
            }
        }

        return st.top() == 't' ? true : false;
    }
};