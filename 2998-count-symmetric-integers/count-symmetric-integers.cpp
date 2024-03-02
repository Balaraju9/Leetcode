class Solution {
public:
    bool fuk(string z1){
        int k=z1.size()/2,s=0,s1=0;
        for(int i=0;i<k;i++){
            s+=(z1[i]-'0');
        }
        for(int i=k;i<z1.size();i++){
            s1+=(z1[i]-'0');
        }
       if(s==s1){
        return true;
       }
       return false;
    } 
    int countSymmetricIntegers(int l, int h) {
        int c=0;
        while(l<=h){
            string z=to_string(l);
            if(z.size()!=0 && z.size()%2==0){
                if(fuk(z)){
                    c++;
                   
                    
                }
            }
            l++;
           
        }
        return c;
    }
    

        
    
    
};