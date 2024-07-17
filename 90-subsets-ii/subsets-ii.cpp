class Solution {
public:
    void fun( vector<int>& n, vector<vector<int>> &v1,vector<int> v2, int i){
        if(i==n.size()){
            v1.push_back(v2);
            return;
        }
        v2.push_back(n[i]);
        fun(n,v1,v2,i+1);
        v2.pop_back();
        fun(n,v1,v2,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& n) {
        map<vector<int>,int> mp;
        vector<vector<int>> v1;
        vector<int> v2;
        int i=0;
        fun(n,v1,v2,i);
        vector<vector<int>> v4;
        for(auto &i:v1){
            sort(i.begin(),i.end());
            if(mp.find(i)==mp.end()){
                v4.push_back(i);
                mp[i]++;
            }
            
        }
        return v4;
        
    }
};