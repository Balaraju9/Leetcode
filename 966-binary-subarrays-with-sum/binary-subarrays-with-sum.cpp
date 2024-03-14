class Solution {
public:
    int numSubarraysWithSum(vector<int>& n, int g) {
        int s=0,t=0,c=0;
        map<int,int> mp;
        for(int i=0;i<n.size();i++){
            s=s+n[i];
            t=s-g;
            if(t>=0 && mp.find(t)!=mp.end()){
                c+=mp[t];
            }
            if(t==0){
                c++;
            }
            mp[s]++;

        }
        return c;
        
    }
};