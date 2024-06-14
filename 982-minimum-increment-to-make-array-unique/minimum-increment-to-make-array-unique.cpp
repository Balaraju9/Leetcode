class Solution {
public:
    int minIncrementForUnique(vector<int>& n) {
        sort(n.begin(),n.end());
        unordered_map<int,int> mp;
        int c=0,max1=0;
        for(int i=0;i<n.size();i++){
            if(mp.find(n[i])==mp.end()){
                mp[n[i]]=i;
                max1=max(max1,n[i]);
            }
            else{
                int k=abs(max1-n[i])+1;
                mp[k+n[i]]=i;
                max1=max(max1,k+n[i]);
                c=c+k;

                
            }
        }
        return c;
        
    }
};