class Solution {
public:
    int minSwaps(string s) {
        int one=0;
        int zero=0;
        for(auto &i:s){
            if(i=='1'){
                one++;

            }
            else{
                zero++;

            }
        }
       if(abs(one-zero)>1) return -1;
        int wast=0,wast1=0;
        char sul='0',sul1='1';
        for(int i=0;i<s.size();i++){
          if(sul!=s[i]){
            wast++;

          }
          if(sul1!=s[i]){
            wast1++;
          }
          if(sul=='0'){
            sul='1';
          }
          else
          {
            sul='0';
          }
          if(sul1=='1'){
            sul1='0';

          }
          else{
            sul1='1';

          }
        }
       
        
    
       if(one==zero) return min(wast,wast1)/2;
       if(one>zero) return wast1/2;
       return wast/2;
    }
};