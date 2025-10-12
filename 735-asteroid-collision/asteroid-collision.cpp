class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
       int i=0;
       while(i<a.size()){
        while(i<a.size() && !st.empty() && (st.top()>0 && a[i]<0)){
            if(st.top()>a[i]*-1){
                i++;
            }
            else if(st.top()==a[i]*-1){
                i++;
                st.pop();
            }
            else{
                st.pop();
            }
        }
        // while(i<a.size() && !st.empty() && (st.top()<0 && a[i]>0)){
        //     if(st.top()*-1>a[i]){
        //         i++;
        //     }
        //     else if(st.top()*-1==a[i]){
        //         i++;
        //         st.pop();
        //     }
        //     else{
        //         st.pop();
        //     }
        // }
        if(i<a.size()){
        st.push(a[i]);
        }
        i++;

       }
       a.clear();
       while(!st.empty()){
        a.push_back(st.top());
        st.pop();
       }
       reverse(a.begin(),a.end());
       return a;
        
    }
};