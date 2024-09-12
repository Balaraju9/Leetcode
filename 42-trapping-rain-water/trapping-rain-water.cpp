class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> v1(h.size());
        vector<int> v2(h.size());
        int max1=0;
        for(int i=0;i<v1.size();i++){
            v1[i]=max1;
            max1=max(max1,h[i]);
        }
        max1=0;
          for(int i=v2.size()-1;i>=0;i--){
            v2[i]=max1;
            max1=max(max1,h[i]);
        }
      
        int ans=0;
        int min1=0;
        for(int i=0;i<h.size();i++){
            min1=min(v1[i],v2[i]);
            if(min1-h[i]>=1){

            ans+=abs(min1-h[i]);
            }
        }
        return ans;


        
    }
};