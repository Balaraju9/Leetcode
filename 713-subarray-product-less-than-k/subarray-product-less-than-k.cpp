class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& n, int k) {
        long long i=0,j=0,c=0,s=1;
        
        while(j<n.size()){
            s=s*n[j];
            while(s>=k && i<=j && j<=n.size()){
                s=s/n[i];
                i++;
            }
            c=c+(j-i)+1;
            j++;
            
            
        }
        return c;
        
    }
};