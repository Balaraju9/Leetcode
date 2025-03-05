class Solution {
public:
    long long coloredCells(int n) {
        
    
       long long int s=1;
       for(int i=1;i<n;i++){
        s=s+(4*i);
       }
       return s;


    }
};