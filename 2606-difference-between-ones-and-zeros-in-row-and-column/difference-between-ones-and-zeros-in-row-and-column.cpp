class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        vector<vector<int>> v1;
        vector<vector<int>> v2;
        int c=0,c1=0;
        for(int i=0;i<g.size();i++){
            c=0;
            c1=0;
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1){
                    c++;
                }
                else{
                    c1++;
                }
            }
            v1.push_back({c,c1});
        }
        int c3=0,c2=0;
        for(int j=0;j<g[0].size();j++){
            c2=0;
            c3=0;
            for(int i=0;i<g.size();i++){
                if(g[i][j]==1){
                    c2++;
                }
                else{
                    c3++;
                }
            }
            v2.push_back({c2,c3});
        }
       
        vector<int> v4;
        vector<vector<int>> v5;
        
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                int t=(v1[i][0]+v2[j][0])-(v1[i][1]+v2[j][1]);
                v4.push_back(t);

            }
            v5.push_back(v4);
            v4.clear();
        }
        return v5;

    }
};