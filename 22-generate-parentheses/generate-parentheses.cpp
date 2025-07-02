class Solution {
public:
    vector<string> v1;
    void fun(int n,string s1,int op,int cl){

        if(op==n && cl==n){
v1.push_back(s1);
        }
        if(op<n){
            fun(n,s1+'(',op+1,cl);
        }
        if(cl<op){
            fun(n,s1+')',op,cl+1);
        }

    }
    vector<string> generateParenthesis(int n) {

        fun(n,"",0,0);
        
        return v1;
    }
};