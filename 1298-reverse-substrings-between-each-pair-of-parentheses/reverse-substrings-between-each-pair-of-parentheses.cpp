class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string s1;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                while(st.top()!='('){

                    s1+=st.top();
                    st.pop();
                }
                if(st.top()=='('){
                    st.pop();
                }
               
                for(auto &i:s1){
                    st.push(i);
                }
                s1="";
                 
            }
            else{
                st.push(s[i]);
            }
        }
        s1="";
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
         reverse(s1.begin(),s1.end());
        return s1;
        
    }
};