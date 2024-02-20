class Solution {
public:
    string addBinary(string a, string b) {
       
        int i=a.size()-1;
        int j=b.size()-1;
        int c=0;
        string s1="";
        while(i!=-1&& j!=-1){
            if(c+(a[i]-48)+(b[j]-48)==2){
                c=1;
                s1+='0';
                i--;
                j--;
            }
            else if(c+(a[i]-48)+(b[j]-48)==3){
                s1+='1';
                c=1;
                i--;
                j--;
            }
            else if(c+(a[i]-48)+(b[j]-48)==0){
                s1+='0';
                c=0;
                i--;
                j--;
            }
            else{
                s1+='1';
                c=0;
                i--;
                j--;
            }


        }
 if(a.size()==b.size() && c){
            s1+='1';
            c=0;
        }


        while(i!=-1){
     if(c+(a[i]-48)==2){
                c=1;
                s1+='0';
                i--;
                
            }
 else if(c+(a[i]-48)==0){
                s1+='0';
                c=0;
                i--;
                
            }
            else{
                s1+='1';
                c=0;
                i--;
                
            }

        }
        
        while(j!=-1){
     if(c+(b[j]-48)==2){
                c=1;
                s1+='0';
                j--;
                
            }
 else if(c+(b[j]-48)==0){
                s1+='0';
                c=0;
                j--;
                
            }
            else{
                s1+='1';
                c=0;
                j--;
                
            }

        }
if(c){
    s1+='1';
}
reverse(s1.begin(),s1.end());
       
        return s1;
        
    }
};