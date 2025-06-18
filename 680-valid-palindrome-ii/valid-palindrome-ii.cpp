class Solution {
public:
    bool fun(int l,int h,string &s){
        while(l<=h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    bool validPalindrome(string s) {

        int l=0,h=s.size()-1;
        while(l<=h){
            if(s[l]!=s[h]){
                if(fun(l+1,h,s) || fun(l,h-1,s)){
                    return true;

                }
                else{
                    return false;

                }

            }
            else{
                l++;
                h--;
            }

            
        }
        return true;
        
    }
};