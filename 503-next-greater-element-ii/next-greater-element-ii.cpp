class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& n) {
        stack<int> st;
        vector<int> v1;
        reverse(n.begin(),n.end());
        for(int i=0;i<2*n.size();i++){
             int k=(i%(n.size()));
            while(!st.empty()){
                if(st.top()>n[k]){
                    break;
                }

                st.pop();
            }
            if(st.empty()){
                st.push(n[k]);
                v1.push_back(-1);


            }
            else if(st.top()>n[k]){
                v1.push_back(st.top());
                st.push(n[k]);
            }
            
               

            


        }
        vector<int> v2;
        for(int i=v1.size()-1;i>=n.size();i--){
            v2.push_back(v1[i]);
        }
        return v2;
        
    }
};