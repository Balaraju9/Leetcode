class Solution {
public:
    int maxProfit(vector<int>& p) {
        int min1=INT_MIN,max1=INT_MIN;
    for(int i=p.size()-1;i>=0;i--){
        if(i==p.size()-1){
            min1=p[i];
            p[i]=0;
        }
        else{
            min1=max(min1,p[i]);
            p[i]=min1-p[i];
        }
        max1=max(max1,p[i]);
    }
    return max1;
        
    }
};