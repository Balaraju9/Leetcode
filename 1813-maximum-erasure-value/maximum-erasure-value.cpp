class Solution {
public:
    int maximumUniqueSubarray(vector<int>& n) {
        int i=0,j=0;
        unordered_map<int,int> mp;;
        int max1=0,s=0;
        while(j<n.size()){
            s+=n[j];
            mp[n[j]]++;
            while(mp.find(n[j])!=mp.end() && mp[n[j]]>1){
                s=s-n[i];
                mp[n[i]]--;
                i++;

            }
            max1=max(max1,s);
            j++;
            
        }
        return max1;
        
    }
};