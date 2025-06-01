class Solution {
public:
    int distributeCandies(int n, int l) {
        int c;
        for(int i=0;i<=l;i++){
            for(int j=0;j<=l;j++){
                for(int k=0;k<=l;k++){
                    if(i+j+k == n){
                        c++;
                    }
                }
            }
        }
        return c;
        
    }
};