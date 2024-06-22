class Solution {
public:
    void fun(int n,int &c){
        if(n==0){
            return ;
        }
        if(n%2==0){
            fun(n/2,c=c+1);
        }
        else{
            fun(n-1,c=c+1);
        }
    }
    int numberOfSteps(int num) {
        int c=0;

         fun(num,c);
         return c;
        
    }
};