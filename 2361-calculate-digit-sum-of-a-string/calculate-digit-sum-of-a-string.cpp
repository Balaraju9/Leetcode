class Solution {
public:
    string fun(string g,int k){
        int pi=0;
        int i=0,c=0;
        string s2="",g1="";
       while(i<g.size()){
           if(c==k){
               for(int j=0;j<g1.size();j++){
                   pi+=g1[j]%48;
                   
               }
               s2+=to_string(pi);
               pi=0;
               c=0;
               g1="";

           }
          
           g1+=g[i];
            i++;
           c++;
       }
       if(c!=0){
           int k=g.size()-c;
         for(int j=k;j<g.size();j++){
                   pi+=g[j]%48;
                   
               }
               s2+=to_string(pi);
               c=0;
           
       }
       
       return s2;

    }
    string digitSum(string s, int k) {

        while(s.size()>k){
            s=fun(s,k);
        }
        return s;
        
        





    }
};