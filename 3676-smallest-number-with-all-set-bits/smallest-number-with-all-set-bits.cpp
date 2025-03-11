class Solution {
public:
    int smallestNumber(int n) {
        int k=1;
        int p=1;
        while(n>k){
            k=k+pow(2,p);
            p++;
        }
        return k;
        
    }
};