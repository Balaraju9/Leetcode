class Solution {
public:
    bool fun(int mid,vector<int> &b,int m,int k){
        int c=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=mid){
                c++;
                if(c>=k){
                    m--;
                    c=0;
                }
            }
            else{
                c=0;
            }
            if(m<=0) return true;
        }
        return false;
    }
    int minDays(vector<int>& b, int m, int k) {
        if((long long)m*k>b.size()) return -1;
        int mind=*min_element(b.begin(),b.end());
        int maxd=*max_element(b.begin(),b.end());
        while(mind<=maxd){
            int mid=(mind+maxd)/2;
            if(fun(mid,b,m,k)){
                maxd=mid-1;
            }
            else{
                mind=mid+1;

            }
        }
       return mind;
        
    }
};