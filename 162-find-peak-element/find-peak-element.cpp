class Solution {
public:
    int findPeakElement(vector<int>& n) {
        int i=0;
        int j=n.size()-1;
        int max1=INT_MIN,su=0;
        while(i!=j){
            if(n[i]>=n[j]){
                j--;
               if(max1<n[i]){
                    max1=n[i];
                    su=i;
                }
            }
            else{
                i++;
                if(max1<n[j]){
                    max1=n[j];
                    su=j;
                }
            }
        }
        return su;
        
    }
};