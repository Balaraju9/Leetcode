class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       long long int s=0,ans=0;

        int even=0,odd=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            if(s&1){
                ans+=even+1;
                odd++;
            }
            else{
                ans+=odd;
                even++;
            }

            
        }
        return ans%1000000007;
        
    }
};