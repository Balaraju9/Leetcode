class Solution {
public:
    int numOfSubarrays(vector<int>& ar, int k, int t) {
        int i=0,j=0;
        int s=0,c=0;
        while(j<ar.size()){
            s+=ar[j];
            if((j-i)+1==k){
                cout<<s;
                if(s/k>=t){
                    c++;

                }
                
                    s=s-ar[i];
                    i++;
                
            }
            
            j++;
            
        }
        return c;

        
    }
};