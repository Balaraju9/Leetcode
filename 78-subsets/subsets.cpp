class Solution {
public:
    void fun(vector<int> n,int i,vector<int> v1,vector<vector<int>> &v2){
        if(i==n.size()){
            v2.push_back(v1);
            return;
        }
        v1.push_back(n[i]);
        fun(n,i+1,v1,v2);
        v1.pop_back();
        fun(n,i+1,v1,v2);
    }
    vector<vector<int>> subsets(vector<int>& n) {
        vector<int> v1;
        vector<vector<int>> v2;
        int i;
        fun(n,i,v1,v2);
        return v2;
        
    }
};