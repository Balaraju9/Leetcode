class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
     
        int pu=0;
      
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                  unordered_map<int,int> mp;
                if(i+2<grid.size() && j+2<grid[i].size()){
                    int s=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                    int s1=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                    int s3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                    int c=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                     int c1=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                      int c2=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                      int d1= grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
                       int d2=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                       if((s==s1 && s1==s3 && s==s3) && (c==c1 && c1==c2 && c==c2) &&(d1==d2)){
                        for(int z=i;z<=(i+2);z++){
                            for(int z1=j;z1<=(j+2);z1++){
                               
                                if(grid[z][z1]<=9 && grid[z][z1]>=1){
                                mp[grid[z][z1]]++;
                                }
                                

                            }
                        }
                       
                        if(mp.size()==9){
                        pu++;
                        }
                       }
                }
                mp.clear();
            

            }
        }
            return pu;
        
    }
};