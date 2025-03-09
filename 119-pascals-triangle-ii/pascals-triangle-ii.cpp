class Solution {
public:
    vector<int> getRow(int r) {
        int balu=r;
        vector<vector<int>> v1;
        v1.push_back({1});
        v1.push_back({1,1});
        if(v1.size()-1>=r){
            return v1[r];
        }
        r=r-1;
        while(r>0){
            vector<int> v3;
            v3.push_back(1);
            vector<int> v4=v1[v1.size()-1];
            for(int i=1;i<v4.size();i++){
                v3.push_back(v4[i]+v4[i-1]);
            }
            v3.push_back(1);
            v1.push_back(v3);
            r--;
        }
        // for(auto &i:v1){
        //     for(auto &j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return v1[balu];
        
    }
};