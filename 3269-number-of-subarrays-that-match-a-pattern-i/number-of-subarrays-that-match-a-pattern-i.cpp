class Solution {
public:
    int countMatchingSubarrays(vector<int>& n, vector<int>& p) {
        map<vector<int>,int> mp;
        vector<int> v2;
        int i=0,j=0;
        int k=p.size();
        for(int i=0;i<n.size();i++){
            if(i+k<=n.size()-1){
            for(int j=i;j<i+k;j++){
                if(n[j]>n[j+1]){
                    v2.push_back(-1);

                }
                else if(n[j]<n[j+1]){
                    v2.push_back(1);

                }
                else{
                    v2.push_back(0);

                }
            }
            mp[v2]++;
            v2.clear();
            }
            
        }
       return mp[p];


        
    }
};