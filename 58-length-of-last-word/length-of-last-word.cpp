class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=0,j=0;
        for(i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                break;
            }


        }
        for(j=i;j>=0;j--){
            if(s[j]==' '){
                break;
            }
        }
        
        return i-j;
    }
};