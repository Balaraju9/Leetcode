class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        int k=m+n;
        k=k-1;
        m=m-1;
        n=n-1;
        int z=k;
        while(n!=-1){
            if(m>=0 && n1[m]>n2[n]){
                n1[k--]=n1[m];
                m--;
            }
            else{
                n1[k--]=n2[n];
                n--;
            }
        }
      
        
    }
};