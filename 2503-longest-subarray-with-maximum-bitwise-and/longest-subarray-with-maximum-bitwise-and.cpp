class Solution {
public:
    int longestSubarray(vector<int>& n) {
        int max1=*max_element(n.begin(),n.end());
        int c=0,max2=1;
        for(int i=1;i<n.size();i++){
            if(n[i]==max1 && n[i-1]==max1){
                max2=max(max2,++c+1);
            }
            else{
                c=0;
            }

        }
        return max2;
        
    }
};