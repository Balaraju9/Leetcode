class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        vector<pair<int,int>> v1;
        for(int i=1;i<m.size();i++){
            int cur=m[i][0];
            int cur2=m[i][1];
            int pr=m[i-1][0];
            int pr1=m[i-1][1];
            if(cur>=pr && cur<=pr1){
                cur=min(cur,pr);
                cur2=max(cur2,pr1);
                m[i][0]=cur;
                m[i][1]=cur2;
                m[i-1][0]=-1;
                m[i-1][1]=-1;

            }

            
        }
       
       for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            if(m[i][j]!=-1){
                v1.push_back({m[i][0],m[i][1]});
                break;
            }
        }
       }
        int c=0;
        for(int i=1;i<v1.size();i++){
            c+=v1[i].first-v1[i-1].second;
            c--;
        }
        if(v1[v1.size()-1].second<days){
            c=c+(days - v1[v1.size()-1].second );
        }
        if(v1[0].first>1 && days>1){
            c=c+(v1[0].first - 1);
        }
        return c;
        
    }
};