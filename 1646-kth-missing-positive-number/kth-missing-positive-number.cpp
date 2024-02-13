class Solution {
public:
    int findKthPositive(vector<int>& ar, int k) {
        int i=0,j=1;
       while(k!=0){
           
           if(i<ar.size() && ar[i]==j){
               i++;
               j++;
           }
           else if(i>=ar.size()){
               j++;
               k--;
           }
           else{
               j++;
               k--;
           }
       }
       return j-1;
    }
};