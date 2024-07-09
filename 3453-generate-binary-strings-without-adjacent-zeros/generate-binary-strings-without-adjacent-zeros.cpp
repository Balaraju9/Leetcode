class Solution {
public:
    void fun(int n,vector<string> &v1,string s){
        if(s.size()==n){
            v1.push_back(s);
           
            return;
        }
        fun(n,v1,s+'1');
        if(s.empty()||s[s.size()-1]=='1'){
      
        fun(n,v1,s+'0');
        }
        


    }

    
    vector<string> validStrings(int n) {
        vector<string> v1;
        string g;
        fun(n,v1,g);
        return v1;
        
    }
};