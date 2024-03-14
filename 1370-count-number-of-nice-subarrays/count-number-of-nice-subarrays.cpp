class Solution {
public:
    int numberOfSubarrays(vector<int>& n, int k) {
        unordered_map<int,int> mp;
        int s=0,t=0,c=0;
        for(int i=0;i<n.size();i++){
            if(n[i]%2!=0){
                s+=1;
            }
            t=s-k;
            if(t==0){
                c++;
            }
            if(mp.find(t)!=mp.end()){
                c+=mp[t];
            }
            mp[s]++;
        }
        return c;
        
    }
};