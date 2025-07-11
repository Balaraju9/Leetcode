class Solution {
public:
    vector<vector<int>> v2;
    void fun(vector<int> &n,int i,vector<int> &v1,vector<bool> &us){
        if(v1.size()>=n.size()){
            v2.push_back(v1);
            return;
        }
        for(int i=0;i<n.size();i++){
            if(us[i]==true) continue;
            us[i]=true;
            v1.push_back(n[i]);
            fun(n,i,v1,us);
            us[i]=false;
            v1.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& n) {
        vector<bool> us(n.size(),false);
        vector<int> v1;
        fun(n,0,v1,us);
        return v2;
    }
};