class Solution {
public:
    int maxProfit(vector<int>& p) {
        int max1=0;
        int k=p[0];
        for(int i=1;i<p.size();i++){
            max1=max(max1,p[i]-k);
           
            k=min(p[i],k);
        }
        return max1;
        
    }
};