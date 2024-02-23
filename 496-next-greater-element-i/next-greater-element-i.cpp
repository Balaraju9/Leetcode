class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        stack<int> st;
        vector<int> v1;
        for(int i=n2.size()-1;i>=0;i--){
              while(!st.empty()){
                    if(st.top()>n2[i]){
                        break;
                    }
                    st.pop();
                }
            if(st.empty()){
                v1.push_back(-1);
                st.push(n2[i]);
            }
            else if(st.top()>n2[i]){
                v1.push_back(st.top());
                st.push(n2[i]);

            }
           
              
             
               
            
            
        }
        vector<int> ba;
        reverse(v1.begin(),v1.end());
        
        for(int i=0;i<n1.size();i++){
            for(int j=0;j<n2.size();j++){
                if(n1[i]==n2[j]){
                    ba.push_back(v1[j]);
                    break;
                }
            }
        }
        return ba;
        
    }
};