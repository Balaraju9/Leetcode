class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=n2.size()-1;i>=0;i--){
           while(!st.empty() && n2[i]>st.top()){
            st.pop();

           }
           if(st.empty()){
            mp[n2[i]]=-1;
            st.push(n2[i]);
           }
           else{
            mp[n2[i]]=st.top();
           
            st.push(n2[i]);
           }
        }
    for(int i=0;i<n1.size();i++){
        n1[i]=mp[n1[i]];
    }
    return n1;
        
    }
};