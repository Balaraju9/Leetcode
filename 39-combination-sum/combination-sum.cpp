class Solution {
public:
    void fun(vector<int>& c, int t,vector<vector<int>> &v1,vector<int> v2,int i,int s){
        if(i==c.size()||s>t){
           
            
            return;
        }
        if(s==t){
            v1.push_back(v2);
           
          
            return;
        }
        v2.push_back(c[i]);
        fun(c,t,v1,v2,i,s+c[i]);
        v2.pop_back();
        if(i+1<c.size()){
            
        fun(c,t,v1,v2,i+1,s);
        }
        
       
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> v1;
        vector<int> v2;
        int i=0;
        int s=0;
        fun(c,t,v1,v2,i,s);
        return v1;
        


    }
};