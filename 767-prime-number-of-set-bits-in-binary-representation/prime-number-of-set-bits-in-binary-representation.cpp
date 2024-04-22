class Solution {
public:
    bool isprime(int c){
        if(c==0){
            return false;
        }
        if(c==1){
            return false;
        }
        if(c==2){
            return true;
        }
        for(int i=2;i<=c/2;i++){
            if(c%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int l, int r1) {
        int c=0,r=0;
        int z=0;
        vector<int> v1;
        for(int i=l;i<=r1;i++){
            c=0;
            r=0;
            int k=i;
            while(k>0){
                r=k%2;
                if(r==1){
                    c++;
                }
                k=k/2;
            }
           if(isprime(c)){
            z++;
           }
        }
        
        return z;
        
        
    }
};