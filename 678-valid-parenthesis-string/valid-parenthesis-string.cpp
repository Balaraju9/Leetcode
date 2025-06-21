class Solution {
public:
    bool checkValidString(string s) {

        int star=0;
     
        int c1=0,star1=star;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                c++;
            }
            else if(s[i]=='*'){
                star++;
            }
            else if(s[i]==')'){
                c--;
            }

            if(c<0 && star>0){
                c=0;
                star--;
            }
            else if(c<0 && star<=0){
                return false;
            }
        }
         for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                c1++;
            }
            else if(s[i]=='*'){
                star1++;
            }
            else if(s[i]=='('){
                c1--;
            }

            if(c1<0 && star1>0){
                c1=0;
                star1--;
            }
            else if(c1<0 && star1<=0){
                return false;
            }
        }
        return true;
    }
};