class Solution {
public:
    int minCost(string c, vector<int>& n) {
      stack<pair<char,int>> st;
      int c1=0;
      for(int i=0;i<n.size();i++){
        if(!st.empty() && st.top().first==c[i]){
            if(n[i]<st.top().second){
                c1+=n[i];

            }
            else{
                c1+=st.top().second;
                st.pop();
                st.push({c[i],n[i]});

            }
        }
        else{
             st.push({c[i],n[i]});
        }
      }
        return c1;
    }
};