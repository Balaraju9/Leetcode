class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int i, int j, int col) {
        int col1=img[i][j];
        queue<pair<int,int>> q;
        vector<vector<bool>> v1(img.size(),vector<bool>(img[i].size(),false));
        q.push({i,j});
        img[i][j]=col;
        v1[i][j]=true;
        while(!q.empty()){
            auto pu=q.front();
            q.pop();
            int i1=pu.first;
            int j1=pu.second;
            if(i1+1<img.size() && img[i1+1][j1]==col1 && v1[i1+1][j1]==false){
                q.push({i1+1,j1});
                img[i1+1][j1]=col;
                v1[i1+1][j1]=true;
            }
            if(j1+1<img[i1].size() && img[i1][j1+1]==col1 && v1[i1][j1+1]==false){
                q.push({i1,j1+1});
                img[i1][j1+1]=col;
                v1[i1][j1+1]=true;
            }
            if(i1-1>=0 && img[i1-1][j1]==col1&& v1[i1-1][j1]==false){
                q.push({i1-1,j1});
                img[i1-1][j1]=col;
                v1[i1-1][j1]=true;
            }
            if(j1-1>=0&& img[i1][j1-1]==col1 && v1[i1][j1-1]==false){
                q.push({i1,j1-1});
                img[i1][j1-1]=col;
                v1[i1][j1-1]=true;
            }
        }
        return img;
    }
};