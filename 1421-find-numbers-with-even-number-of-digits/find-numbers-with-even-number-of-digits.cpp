class Solution {
public:
    int findNumbers(vector<int>& n1) {
        int c=0;
        for(int i=0;i<n1.size();i++){
            int n=n1[i];
        if(n>10 && n<100 || (n>999 && n<=9999 ) || (n>99999 && n<=999999)){
            c++; 
        }
        }
        return c;
        
    }
};