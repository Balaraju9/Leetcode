class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<long long int,pair<long long int,long long int>> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int> sumr(mat.size());
        long long int s=0;
        vector<long long int> sumc(mat[0].size());
        for(int i=0;i<mat.size();i++){
            s=0;
            for(int j=0;j<mat[i].size();j++){
                s+=mat[i][j];
            }
            sumr[i]=s;

        }
        s=0;
        for(int j=0;j<mat[0].size();j++){
            s=0;
            for(int i=0;i<mat.size();i++){
                s+=mat[i][j];
            }
            sumc[j]=s;
        }
        for(int i=0;i<arr.size();i++){
            auto i1=mp[arr[i]];
            int i2=i1.first;
            int j2=i1.second;
            sumr[i2]=sumr[i2]-arr[i];
        
            if(sumr[i2]==0){
              
                return i;
            }
            sumc[j2]=sumc[j2]-arr[i];
            if(sumc[j2]==0){
                cout<<j2;
                return i;
            }
         
        }

        return 3;
        
    }
};