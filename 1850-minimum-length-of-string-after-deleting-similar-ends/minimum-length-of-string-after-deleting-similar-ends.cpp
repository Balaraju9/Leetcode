class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                char pu=s[i];
                while(s[i]==pu){
                    if(i>j){
                        break;
                    }
                    
                    i++;
                }
                while(s[j]==pu){
                    if(i>j){
                        break;
                    }
                   
                    j--;
                }
            }
            else{
                break;
            }
           
        }
        if(i<=j){
            return abs(i-j)+1;
        }

        return 0;
        
    }
};