class Solution {
public:
    vector<int> getFinalState(vector<int>& n, int k, int m) {
        vector<pair<int,int>> v1;
        for(int i=0;i<n.size();i++){
            v1.push_back({n[i],i});
        }
       
     
        while(k--){
             sort(v1.begin(),v1.end());
            for(auto &i:v1){
                i.first=i.first*m;
                break;
            }

        }
        for(auto &i:v1){
            n[i.second]=i.first;
        }
        return n;
        
    }
};