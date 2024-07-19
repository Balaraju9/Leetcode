class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(st.empty() && s[i]==')'){
                c++;
            }
            else if(s[i]==')' && st.top()=='(' ){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size()+c;
        
    }
};