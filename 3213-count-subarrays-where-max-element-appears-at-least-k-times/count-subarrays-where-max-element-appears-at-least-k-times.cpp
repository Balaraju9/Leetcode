class Solution {
public:
    long long countSubarrays(vector<int>& n, int k) {
        long long i=0,j=0,s=0,max1=0;
        long long k1=*max_element(n.begin(),n.end());
        unordered_map<int,int> mp;
        while(j<n.size()){
            mp[n[j]]++;
            
            while(mp[k1]>=k && i<=j && j<n.size()){
             
                s=s+(n.size()-j);
                
                mp[n[i]]--;
                i++;
                
                

            }
            j++;
        }
        return s;
        
    }
};