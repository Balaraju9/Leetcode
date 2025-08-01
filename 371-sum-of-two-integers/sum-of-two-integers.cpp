class Solution {
public:
    int getSum(int a, int b) {
        int c=a^b;
        while(a!=0){
            c=a^b;
            a=a&b;
        a=a<<1;
        b=c;

        }
        return c;
        
    }
};