class Solution {
public:
    string fun(string s1){
        string s2="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='1'){
                s2+="0";

            }
            else{
                s2+="1";

            }
            
        }
        return s2;
    }
    char findKthBit(int n, int k) {
        string s1="0";
        string s2="";
        while(s2.size()<=k){
            
            string b1=fun(s1);
            reverse(b1.begin(),b1.end());
            s2=s1+"1"+b1;
            s1=s2;
            

        }
        cout<<s2;
        return s2[k-1];
        
    }
};