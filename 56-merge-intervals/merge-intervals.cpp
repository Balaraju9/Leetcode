class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v1) {
        sort(v1.begin(),v1.end());
        vector<vector<int>> v2;
        for(int i=1;i<v1.size();i++){
            int cur1=v1[i][0];
            int cur2=v1[i][1];
            int pr1=v1[i-1][0];
            int pr2=v1[i-1][1];
            if(cur1>=pr1 && cur1<=pr2){
                v1[i][0]=min(cur1,pr1);
                v1[i][1]=max(cur2,pr2);
                v1[i-1][0]=-919;
                v1[i-1][1]=-919;
            }
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i][0]==-919){

            }
            else{
                v2.push_back({v1[i][0],v1[i][1]});
            }
        }
        return v2;
        
    }
};