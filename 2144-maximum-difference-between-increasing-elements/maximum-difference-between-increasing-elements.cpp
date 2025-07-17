class Solution {
public:
    int maximumDifference(vector<int>& n) {
        int max1=n[n.size()-1];
        int ans=-1;
        int ans1=-1;
        for(int i=n.size()-2;i>=0;i--){
            if(n[i]<max1){
                ans=(max1-n[i]);
                ans1=max(ans,ans1);
            }
            max1=max(max1,n[i]);

        }
        return ans1;
        
    }
};