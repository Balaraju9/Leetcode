class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        string s="";
        int r=0;
        for(int i=2;i<n-1;i++){
            int t=i;
            while(t!=0){
                r=t%2;
                s=s+to_string(r);
                t=t/2;

            }
            string z=s;
            reverse(z.begin(),z.end());
            if(z==s){
                continue;
            }
            return false;
        }
        return true;
        
    }
};