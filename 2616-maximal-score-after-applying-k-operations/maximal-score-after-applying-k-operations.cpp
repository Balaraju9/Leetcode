class Solution {
public:
    long long maxKelements(vector<int>& n, int k) {
        sort(n.begin(),n.end(),greater<int>());
        priority_queue<double> st;
        long long ans=0;
        int k3=k;
        
        for(int i=0;i<n.size();i++){
            st.push(n[i]);
            k3--;
            if(k3<=0){
                break;
            }
        }
        while(k--){
            
            ans+=st.top();
            double k1=ceil(st.top()/3);
            st.pop();
            st.push(k1);
            

        }
       
        return ans;
    }
};