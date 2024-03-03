class Solution {
public:
    void rotate(vector<vector<int>>& ar) {
        int i=0,j=0,c=0;
        vector<int> v1;
        vector<vector<int>> v2;
       while(j<ar[i].size()){
            v1.push_back(ar[i][j]);
           i++;
           c++;
           
           if(c==ar.size()){
               i=0;
               j++;
               c=0;
               reverse(v1.begin(),v1.end());
               v2.push_back(v1);
               v1.clear();
           }
          
       }
      for(int i=0;i<v2.size();i++){
          for(int j=0;j<v2.size();j++){
              ar[i][j]=v2[i][j];
          }

      }

        
        
    }
};