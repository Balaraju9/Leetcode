class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        int s=0,donga=0;
        vector<int> v1(g[0].size() * g[0].size());
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                int ind=g[i][j]-1;
                if(v1[ind]<0){
                    donga=g[i][j];
                }
                else{
                    v1[ind]=-1;
                   
                }
                s+=g[i][j];
            }
        }

        s=s-donga;
        int n=v1.size();
       int tot=(n*(n+1))/2;
       tot=tot-s;
        // tot=tot-s;
        // cout<<s<<" "<<tot;
        return {donga,tot};
        
        
    }
};