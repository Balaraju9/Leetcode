class Solution {
public:
    int longestMonotonicSubarray(vector<int>& n) {
        if(n.size()==1) return 1;
        int c1=0,c=0,max1=0,max2=0;
        for(int i=0;i<n.size()-1;i++){
            if(n[i]<n[i+1]){
                c++;
            }
            else{
                max1=max(max1,c);
                c=0;
            }
             max1=max(max1,c);
              if(n[i]>n[i+1]){
                c1++;
            }
            else{
                max2=max(max2,c1);
                c1=0;
            }
            max2=max(max2,c1);
        }
        return max(max1+1,max2+1);
        
    }
};