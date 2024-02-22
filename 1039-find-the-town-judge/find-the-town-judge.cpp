class Solution {
public:
    Solution(){
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
    }
    int findJudge(int n, vector<vector<int>>& t) {
        if(n==1 && t.size()==0){
            return 1;
        }

        unordered_map<int,int> mp;
        unordered_map<int,int> mp1;
        for(auto &i:t){
            mp[i[0]]++;
            mp1[i[1]]++;
        }
        
        int z=-1;
        for(auto &i:mp1){
            if(mp.find(i.first)==mp.end() && i.second==n-1){
                z=i.first;
                
            }
        }
        return z;
        
    }
};