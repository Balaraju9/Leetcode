class Solution {
public:
    string longestPalindrome(string s) {
        int i=0,j=0,max1=0;
        string lan="";
        for(int i=0;i<s.size();i++){
            
            int k=i;
            int k1=i;
            while(k>=0 && k1<s.size() && s[k]==s[k1]){
                if(k>=0 && k1<s.size()){

            if(max1<(k1-k)+1){
                max1=(k1-k)+1;
                    lan="";
                for(int pu=k;pu<=k1;pu++){
                    lan+=s[pu];


                }

            }
                }
                k--;
                k1++;
            }
            k=i;
             k1=i+1;
            while(k>=0 && k1<s.size() && s[k]==s[k1]){
                if(k>=0 && k1<s.size()){

            if(max1<(k1-k)+1){
                max1=(k1-k)+1;
                    lan="";
                for(int pu=k;pu<=k1;pu++){
                    lan+=s[pu];


                }

            }
                }
                k--;
                k1++;
            }
        }
        return lan;
        
    }
};