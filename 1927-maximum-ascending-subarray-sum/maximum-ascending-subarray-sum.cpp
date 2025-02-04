class Solution {
public:
    int maxAscendingSum(vector<int>& n) {
        int s=0,max1=0;
        if(n.size()==1) return n[0];
        for(int i=0;i<n.size()-1;i++){
            if(n[i]<n[i+1]){
                s+=n[i];
                if(i+1==n.size()-1){
                    s+=n[i+1];
                }
            }
            else{
                s+=n[i];
                max1=max(max1,s);
                s=0;
            }
            max1=max(max1,s);

        }
        return max1;
        
    }
};