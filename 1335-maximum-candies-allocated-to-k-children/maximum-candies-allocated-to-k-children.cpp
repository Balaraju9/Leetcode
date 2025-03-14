class Solution {
public:
    bool fun(vector<int> cp,long long k,int m){
        for(int i=cp.size()-1;i>=0;i--){
            if(cp[i]>=m){
                k=k-(cp[i]/m);
            }
            if(k<=0) return true;
        }
        return false;

    }
    int maximumCandies(vector<int>& c, long long k) {
      
        int l=1;
        int h=*max_element(c.begin(),c.end());
        vector<int> c1=c;
        while(l<=h){
            int m=(l+h)/2;
            if(fun(c1,k,m)==true){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return h;
        
        
    }
};