class Solution {
public:
    string compressedString(string w) {
        int i=0;
        string s1="";
        int c=0;
        for(int i=0;i<w.size();){

            char cur=w[i];
            c=0;
            while(i<w.size() && cur==w[i] ){
                c++;
                i++;
            }
            cout<<i<<" ";
            if(c<=9){
                s1+=to_string(c)+cur;
            }
            else{
                if(c%9==0){
                    int k1=c/9;
                    while(k1--){
                        s1+=to_string(9)+cur;
                    }
                }
                else{
                    int k1=c/9;
                    int k2=k1;
                      while(k1--){
                        s1+=to_string(9)+cur;
                    }
                    s1+=to_string(c%9)+cur;

                }
            }
        }
        return s1;
        
    }
};