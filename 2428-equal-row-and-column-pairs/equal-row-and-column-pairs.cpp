class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        string s1="";
      vector<string> v1;
      vector<string> v2;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                s1+=to_string(g[i][j]);
                 s1+="#";
            }
           
           v1.push_back(s1);
            s1="";
        }
        s1="";
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                s1+=to_string(g[j][i]);
                 s1+="#";
            }
          
           v2.push_back(s1);
            s1="";
        }
        int c=0,c1=0,max1=0;
       
       for(auto &i:v1){
        for(auto &j:v2){
            if(i==j){
                c++;
            }
        }
       }
        return c;
        
    }
};