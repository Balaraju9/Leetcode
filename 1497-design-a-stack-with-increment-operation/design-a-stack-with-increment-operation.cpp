class CustomStack {
public:
    int size;
    stack<int> st;
    CustomStack(int maxSize) {
        size=maxSize;
        
    }
    
    void push(int x) {
        
        if(st.size()<size){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.size()>=1){
            int k=st.top();
            st.pop();
            return k;
        }
        return -1;
        
    }
    
    void increment(int k, int val) {
        if(st.size()>=1){
        stack<int> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty() && k>=1){
            int k1=st1.top();
            st1.pop();
            
                st.push(k1+val);
                k--;
                if(k==0){
                    break;
                }
            
        }
            while(!st1.empty() ){
           st.push(st1.top());
           st1.pop();
            
        }
        }

        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */