class Solution {
public:
    bool checkValidString(string s) {
        int st=0,op=0,cl=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                st++;
            }
            else if(s[i]=='('){
                op++;
            }
            else{
                cl++;
            }
            if(op+st>=cl || op==cl){

            }
            else{
                return false;
            }
        }
         st=0,op=0,cl=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*'){
                st++;
            }
            else if(s[i]==')'){
                op++;
            }
            else{
                cl++;
            }
            if(op+st>=cl || op==cl){

            }
            else{
                return false;
            }
        }
        return true;
        
    }
};