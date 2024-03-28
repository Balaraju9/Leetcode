class Solution {
public:
    int maxSubarrayLength(vector<int>& n, int k) {
        int i=0,j=0,max1=0,max2=0;
        unordered_map<int,int> mp;
        while(j<n.size()){
            mp[n[j]]++;
            max1=max(max1,mp[n[j]]);
             while(max1>k && i<=j){
                mp[n[i]]--;
                 i++;
                max1=min(max1,mp[n[j]]);

               
               }
            
           
                max2=max(max2,(j-i)+1);
            
            
              
            j++;

        }
        return max2;
        
    }
};