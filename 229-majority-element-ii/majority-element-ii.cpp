class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v1;
        sort(nums.begin(),nums.end());
        
        int k=nums.size()/3;
        int i=0;
        int pu;
        for(i=0;i<nums.size();){
            int k2=nums[i];
            pu=0;
            while(i<nums.size() && k2==nums[i] && i<nums.size()){
                i++;
                pu++;
            }

            if(pu>k){
                v1.push_back(k2);
            }
          

        }
        return v1;
        
    }
};