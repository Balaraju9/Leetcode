class Solution {
public:
    int maxSubarraySumCircular(vector<int>& n) {
      
        int t=0,tot=0,max1=INT_MIN,t1=0,min1=INT_MAX;

        for(int i=0;i<n.size();i++){
            if(t1>0){
                t1=0;
            }
            if(t<0){
                t=0;
            }
            tot+=n[i];
            t1+=n[i];
            t+=n[i];
            max1=max(max1,t);
            min1=min(min1,t1);
        }
       
        if(tot==min1){

        }
        else{
        max1=max(max1,tot-min1);
        }return max1;
        
    }
};
