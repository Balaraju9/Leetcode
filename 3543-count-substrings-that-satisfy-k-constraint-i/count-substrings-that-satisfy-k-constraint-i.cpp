class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int i1=0,j1=0;
        int c=0,min1=0;
        for(int i=0;i<s.size();i++){
            i1=0,j1=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='1'){
                    i1++;

                }
                else if(s[j]=='0'){
                    j1++;

                }
                
               
                 if(i1>k && j1>k){
                    break;
                    
                }
                 if(i1<=k || j1<=k){
                    c++;
                }
               

            }
        }
        return c;

        
    }
};