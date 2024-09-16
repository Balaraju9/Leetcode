class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int i=0,j=0;
        int min1=INT_MAX,s=0;
        while(j<nums.size()){
            s+=nums[j];
            while(s>=t && i<nums.size()){
                   if(s>=t){
                    min1=min(min1,(j-i)+1);
                }
                s=s-nums[i];
                i++;
                if(s>=t){
                    min1=min(min1,(j-i)+1);
                }
            }
            j++;

        }
        if(min1==2147483647){
            return 0;
        }
        return min1;
        
    }
};