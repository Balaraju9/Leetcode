class Solution {
public:
    int countCompleteSubarrays(vector<int>& n) {
        int i=0,j=0;
        unordered_map<int,int> mp;
        for(auto &i:n){
            mp[i]++;
        }
        int k=mp.size();
        mp.clear();
        int k1=k-1;
        int s=0,s1=0;
        while(j<n.size()){
            mp[n[j]]++;
            while(mp.size()>k1){
                mp[n[i]]--;
                if(mp[n[i]]==0){
                    mp.erase(n[i]);
                }
                i++;

            }
            s+=(j-i)+1;
            j++;

            
        }
        i=0,j=0;
        mp.clear();
        while(j<n.size()){
            mp[n[j]]++;
            while(mp.size()>k){
                mp[n[i]]--;
                if(mp[n[i]]==0){
                    mp.erase(n[i]);
                }
                i++;

            }
            s1+=(j-i)+1;
            j++;

            
        }
        return s1-s;
        
    }
};