class Solution {
public:
    bool fun(char s,char s1){
        if(isupper(s)&&islower(s1) || isupper(s1)&&islower(s) ){
            if(tolower(s)==tolower(s1)){
                return true;
            }

        }
        return false;
    }
    string makeGood(string s) {
        stack<char> st;
        int i=0,c=0;
        char pu,pu1;
        int h=0;
        while(i<s.size()){
            if(!st.empty()){
                if(fun(s[i],st.top())){
                    st.pop();
                    if(st.empty()){
                        i++;
                        if(i==s.size()){
                            break;
                        }
                        c=0;
                    }
                    else{
                        c=1;
                    }
                }
                
                else{
                    c=0;
                }
            }
            if(c!=1){
                st.push(s[i]);
    
            
            }
            i++;
        }
        
        string s3="";
        while(!st.empty()){
           s3+=st.top();
           cout<<st.top()<<" ";
           
            st.pop();
        }
        reverse(s3.begin(),s3.end());
       
        return s3;
        
    }
};