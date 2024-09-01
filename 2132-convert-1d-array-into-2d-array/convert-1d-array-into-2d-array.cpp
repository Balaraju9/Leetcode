class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        vector<vector<int>> v2;
        vector<int> v1;
        int k;
        for(int i=0;i<o.size();){
            k=n;
            while(i<o.size() && k--){
                v1.push_back(o[i]);
                i++;


            }
            v2.push_back(v1);
            v1.clear();
        }
        if(v2.size()==m && v2[0].size()==n){
            return v2;
        }
        return {};
        
    }
};