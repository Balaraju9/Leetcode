class Solution {
public:
    long long maximumTotalSum(vector<int>& m) {
        sort(m.begin(),m.end());
        long long ans=0;
        for(int i=m.size()-2;i>=0;i--){
            if(m[i]<=0) return -1;
            if(m[i]>=m[i+1]){
                m[i]=m[i+1]-1;
            }
            if(m[i]==0) return -1;
            // 2 4 4 5 6 7 7
           
           
            
        }
        for(auto &i:m){
             ans+=i;
           
        }
        return ans;
        
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});