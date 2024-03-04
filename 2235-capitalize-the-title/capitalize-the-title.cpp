class Solution {
public:
    string capitalizeTitle(string t) {
        int i=0;
        int c=0;

       for(int i=t.size()-1;i>=0;i--){
           if(t[i]==' '){
               if(c>2){
                   t[i+1]=toupper(t[i+1]);
               }
              
               c=0;
           }

           if(t[i]>='A' && t[i]<='Z'){
               t[i]=tolower(t[i]);
           }
           if(t[i]!=' '){
           c++;
           }

       }
       if(c>2){
           t[0]=toupper(t[0]);
       }
      
       
       return t;

        
    }
};