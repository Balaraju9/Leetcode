class Solution {
public:
    int fr(int n){
        return (n*(n-1))/2;
    }
    int tupleSameProduct(vector<int>& n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n.size();i++){
            for(int j=i+1;j<n.size();j++){
                mp[n[i]*n[j]]++;
            }
        }
        int c=0;
        for(auto &i:mp){
            if(i.second>1){
                c+=8*fr(i.second);
            }
        }
        return c;

        
    }
};