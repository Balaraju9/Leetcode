class Solution {
public:
    int maxSum(vector<int>& n) {
        int max1=*max_element(n.begin(),n.end());
        set<int> st;
        int s=INT_MIN;
        for(auto &i:n){
            if( i>0 && st.find(i)==st.end()){
                if(s==INT_MIN){
                    s=0;
                }
                s+=i;
                st.insert(i);
                

            }
            
        }
    return max(max1,s);
        
    }
};