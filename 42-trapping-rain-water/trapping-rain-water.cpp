class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> pu(h.size());
        vector<int> pu1(h.size());
        int max=INT_MIN,max1=INT_MIN    ;
        for(int i=0;i<h.size();i++){
            if(max<h[i]){
                max=h[i];
            }
            pu[i]=max;
        }
        for(int i=h.size()-1;i>=0;i--){
            if(max1<h[i]){
                max1=h[i];
            }
            pu1[i]=max1;
        }
        int s=0;
        for(int i=0;i<h.size();i++){
            int k=min(pu[i],pu1[i]);
            s+=abs(k-h[i]);
        }
       
        return s;
        
    }
};