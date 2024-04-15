class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> v1(t.size());
        for(int i=t.size()-1;i>=0;i--){
            while(!st.empty() && t[i]>=t[st.top()]){
                st.pop();
            }
            if(st.empty()){
                v1[i]=0;
            }
            else{
                v1[i]=abs(i-st.top());
            }
            st.push(i);

        }
        return v1;
        
    }
};