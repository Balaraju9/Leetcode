class Solution {
public:
    int countPrimes(int n) {
        if(n==0|| n==1) return 0;

        vector<bool> v1(n+1,true);
        v1[0]=false;
        v1[1]=false;
        for(int i=2;i<=sqrt(n);i++){
            if(v1[i]==true){
                for(int j=i*i;j<=n;j=j+i){
                    v1[j]=false;
                }
            }
        }
        int c=0;
       for(int i=0;i<v1.size()-1;i++){
      
        if(v1[i]==1) c++;
       }
        return c;

        
    }
};