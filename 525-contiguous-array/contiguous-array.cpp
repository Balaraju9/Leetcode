class Solution {
public:
    int findMaxLength(vector<int>& n) {
        for(int i=0;i<n.size();i++){
            if(n[i]==0){
                n[i]=-1;
            }
        }
        int max1=0,s=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n.size();i++){
            s=s+n[i];
            if(s==0){
                max1=max(max1,i+1);
            }
            else if(mp.find(s)!=mp.end()){
                int k=i-mp[s];
                max1=max(max1,k);
            }
            else{
                mp[s]=i;
            }
            
        }
        return max1;
        
    }
};