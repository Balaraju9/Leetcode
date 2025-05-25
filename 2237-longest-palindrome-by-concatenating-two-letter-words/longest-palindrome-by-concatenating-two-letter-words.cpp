class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        unordered_map<string,int> mp;
        int max1=0,ans=0;
        for(int i=0;i<w.size();i++){
            string z1=w[i];
            reverse(z1.begin(),z1.end());
            if(  mp.find(z1)!=mp.end() && mp[z1]>0){
                ans+=(4);
                mp[z1]--;
            }
            else{
                mp[w[i]]++;
            }
           
        }
            for(int i=0;i<w.size();i++){
          
            if(w[i][0]==w[i][1] && mp[w[i]]>0){
                max1=max(max1,mp[w[i]]);
            }
        }
        cout<<ans<<max1;
        return ans+max1*2;
        
        
    }
};