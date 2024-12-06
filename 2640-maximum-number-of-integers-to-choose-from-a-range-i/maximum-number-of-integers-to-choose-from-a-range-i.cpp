class Solution {
public:
    int maxCount(vector<int>& b, int n, int m) {
        unordered_map<int,int> mp;
        for(int i=0;i<b.size();i++){
            mp[b[i]]++;
        }
        int c=0,s=0;
        for(int i=1;i<=n;i++){
            if(mp[i]>=1){

            }
            else{
                  s=s+i;
                if(s>m) break;
                if(s<=m && s!=0){
                   
                    c++;
                }
                
              
            }
        }
        
        return c;
        
    }
};