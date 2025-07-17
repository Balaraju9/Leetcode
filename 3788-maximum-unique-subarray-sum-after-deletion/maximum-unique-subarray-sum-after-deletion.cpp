class Solution {
public:
    int maxSum(vector<int>& n) {
        int max1=INT_MIN;
        unordered_map<int,int> mp;
        for(auto &i:n){
            if(i>0 && mp.find(i)==mp.end()){
                mp[i]=1;
            }
            else if(i<=0){
                max1=max(max1,i);
            }
        }
        int ans=-1;
        for(auto &i:mp){
            ans+=i.first;
        }
        if(ans==-1) return max1;
        return ans+1;

        
    }
};