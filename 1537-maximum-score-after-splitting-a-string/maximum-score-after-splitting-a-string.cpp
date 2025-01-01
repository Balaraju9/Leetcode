class Solution {
public:
    int maxScore(string s) {
        int max1=0;
        int c=0,c1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                c++;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                c--;
            }
            if(s[i]=='0'){
                c1++;
            }
            if(i!=s.size()-1){
            max1=max(max1,(c+c1));
            }
        }
        return max1;
        
    }
};