class Solution {
public:
    int subarraysDivByK(vector<int>& n, int k) {
        unordered_map<int,int> mp;
        int p=0,k1;
        mp[0]=1;
        
        int cn=0;
        for(int i=0;i<n.size();i++){
            p=p+n[i];
            k1=p%k;
            if(k1<0){
                k1=k1+k;
                
                
            }
           
                cn+=mp[k1];
            
           
            mp[k1]+=1;
        }
        return cn;
    }
};