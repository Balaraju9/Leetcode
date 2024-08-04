class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int> v1;
        long long int s=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                s=s+nums[j];
                s=s%1000000007;
                v1.push_back(s);
            }
            s=0;
        }
        long long int s1=0;
        sort(v1.begin(),v1.end());
     
       
        for(int i=left;i<=right;i++){
            
            s1+=(v1[i-1])%1000000007;
        }
        return s1%1000000007;
        
    }
};