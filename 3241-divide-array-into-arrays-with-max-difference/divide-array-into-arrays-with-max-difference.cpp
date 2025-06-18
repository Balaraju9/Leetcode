class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& n, int k) {
        sort(n.begin(),n.end());
        vector<vector<int>> v2;
        vector<int> v1;
        int c=0;

        for(auto &i:n){
            c++;
            v1.push_back(i);
            if(c==3){
                c=0;
                v2.push_back(v1);
                v1.clear();
            }
        }
        for(int i=0;i<v2.size();i++){
            if(v2[i][2]-v2[i][0]>k){
                return {};

            }
        }
        return v2;
        
    }
};