class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int max1=*min_element(n.begin(),n.end());
        int s=0;
        for(int i=0;i<n.size();i++){
            if(s<0){
                s=0;
            }
                        s+=n[i];

            max1=max(max1,s);
        }
        return max1;
        
    }
};