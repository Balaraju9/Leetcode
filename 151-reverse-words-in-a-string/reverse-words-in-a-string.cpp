class Solution {
public:

    string reverseWords(string s) {
        int i=0,j=0,c=0,c1=0,c2=0;
        while(s[i]==' '){
            i++;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                c1++;
            }
        }
        while(i<s.size()){
            if(s[i]!=' '){
                if(c2==c1){
                    break;
                }
                if(c==1){
                    s[j]=' ';
                    j++;
                    c=0;

                }
                else{
                s[j]=s[i];
                i++;
                j++;
                c2++;
                }
            }
            else{
            i++;
            c=1;
            
            }
        }
        int pu=0,pu1=0;
        for(int i=0;i<s.size();i++){
            if(pu==c1){
                break;
            }
            else if(s[i]!=' '){
                pu++;

            }
            else{
                pu1++;
            }

        }
        s.resize(pu+pu1);
        i=0;
        while(i<s.size()){
            if(s[i]!=' ' ){

                j=i;
                
                while(s[i]!=' '&& i<s.size()){
                    i++;
                }
                int t1=j,t2=i-1;
                while(t1<=t2){
                   swap(s[t1],s[t2]);
                    t1++;
                    t2--;
                }
            }
            else{
                i++;
            }
            
        }
       i=0;
       j=s.size()-1;
       while(i<=j){
           swap(s[i],s[j]);
           i++;
           j--;
       }
        
        return s;
        
    }
};