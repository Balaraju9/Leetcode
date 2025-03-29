class Solution {
public:
    int minimumIndex(vector<int>& n) {
        unordered_map<int,int> mp;
        int pre=0;
        int cur=0,cnt=0;
        vector<int> v1(n.size());
        vector<int> v2(n.size());
        for(int i=0;i<n.size();i++){
            mp[n[i]]++;
            if(cnt==0){
                pre=n[i];

            }
            else if(n[i]==pre){
                cnt++;

            }
            else{
                cnt--;
            }
            if(mp[pre]>(i+1)/2 ){
                v1[i]=pre;

            }

        }
        mp.clear();
        cnt=0,pre=0;
             for(int i=n.size()-1;i>=0;i--){
            mp[n[i]]++;
            if(cnt==0){
                pre=n[i];
                cnt=1;

            }
            else if(n[i]==pre){
                cnt++;

            }
            else{
                cnt--;
            }
            if(mp[pre]>(n.size()-i)/2 ){
                v2[i]=pre;

            }

        }
       
        for(int i=0;i<v1.size()-1;i++){
            if(v1[i]==v2[i+1] && v1[i]!=0){
                return i;
            }
        }
        return -1;
        
    }
};