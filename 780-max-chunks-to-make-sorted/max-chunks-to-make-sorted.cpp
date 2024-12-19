class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        vector<int> pu=arr;
        vector<pair<int,int>> v1;
        sort(pu.begin(),pu.end());
        for(int i=0;i<pu.size();i++){
            int k=mp[pu[i]];
            if(k>i){
                    v1.push_back({i,k});
            }
            else{
                 v1.push_back({k,i});
            }
           
        }
     
        
    for (int i = 1; i < v1.size(); i++) {
    if (v1[i].first >= v1[i-1].first && v1[i].first <= v1[i-1].second) {
        v1[i].first = min(v1[i].first, v1[i-1].first);
        v1[i].second = max(v1[i].second, v1[i-1].second);
        
        v1[i-1].first = -11;
        v1[i-1].second = -11;
    }
}
int c=0;

          for(auto &i:v1){
            if(i.second==-11){

            }
            else{
                c++;
            }
          
            
        }

        return c;
        
    }
};