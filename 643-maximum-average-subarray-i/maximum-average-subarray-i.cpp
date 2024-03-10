class Solution {
public:
    double findMaxAverage(vector<int>& n, int k) {
        double max1=INT_MIN,s=0;
        int i=0,j=0;
        while(j<n.size()){
            s=s+n[j];
            if(((j-i)+1)<k){
                j++;
            }
            else{
                max1=max(max1,(s)/k);
                s=s-n[i];
                i++;
                j++;
            }
        }
        return max1;
        
    }
};