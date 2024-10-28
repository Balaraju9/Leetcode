class Solution {
public:
    int longestSquareStreak(vector<int>& n) {
        vector<long long int> v1;
        for(auto &i:n){
            v1.push_back(i);
        }
        long long int max1=0;
        for(int i=0;i<v1.size();i++){
           if(max1<v1[i]){
            max1=v1[i];
           }
        }
        
        unordered_map<long long int,long long int> mp;
        for(int i=0;i<n.size();i++){
            mp[n[i]]++;
        }
        int ans=-1;
        for(int i=0;i<n.size();i++){
            if(max1>=(v1[i]*v1[i]) && mp.find(v1[i]*v1[i])!=mp.end()){
                int c=0;
                long long  k=v1[i]*v1[i];
                while(mp.find(k)!=mp.end()){
                    c++;
                    k=k*k;

                }
                ans=max(ans,c+1);

            }


        }
        return ans;
    }
};