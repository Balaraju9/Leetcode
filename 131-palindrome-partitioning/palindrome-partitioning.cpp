class Solution {
public:
  
    bool fun1(string &s1){
        int i=0,j=s1.size()-1;
        while(i<=j){
            if(s1[i]!=s1[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void fun(string &s,int i,vector<string> &v1, vector<vector<string>> &v2){
        if(i>=s.size()){
            v2.push_back(v1);
            return;

        }
        for(int j=i;j<s.size();j++){
            string s1=s.substr(i,j-i+1);
            if(fun1(s1)){
                v1.push_back(s1);
            fun(s,j+1,v1,v2);
            v1.pop_back();
            }

        }

    }
     
    vector<vector<string>> partition(string s) {
         vector<vector<string>> v2;
         vector<string>v1;
        fun(s,0,v1,v2);
        return v2;
        
    }
};