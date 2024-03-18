class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& n, vector<int>& t) {
        vector<vector<int>> v1;
        for(int i=0;i<n.size();i++){
            v1.push_back(n[i]);
        }
        v1.push_back(t);
        map<vector<int>,int> mp;
        sort(v1.begin(),v1.end());
        for(int i=0;i<v1.size()-1;i++){
            int k1=v1[i][1];
            if(k1>=v1[i+1][0] && k1<=v1[i+1][1] || k1>v1[i+1][1]){

                if(i>v1.size()-1){
                    break;
                }
                v1[i][1]=max(k1,v1[i+1][1]);
                v1[i+1][0]=v1[i][0];
                v1[i+1][1]=v1[i][1];
                
                
            }
            mp[v1[i]]++;
        }
        mp[v1[v1.size()-1]]++;
       vector<vector<int>> v2;
       for(auto &i:mp){
        v2.push_back(i.first);
       }
       mp.clear();
for(int i=0;i<v2.size()-1;i++){
            int k1=v2[i][1];
            if(k1>=v2[i+1][0] && k1<=v2[i+1][1] || k1>v2[i+1][1]){

                if(i>v2.size()-1){
                    break;
                }
                v2[i][1]=max(k1,v2[i+1][1]);
                v2[i+1][0]=v2[i][0];
                v2[i+1][1]=v2[i][1];
                
                
            }
            mp[v2[i]]++;
            
        }
        mp[v2[v2.size()-1]]++;
        v2.clear();
        for(auto &i:mp){
        v2.push_back(i.first);
       }



        return v2;
    }
};
