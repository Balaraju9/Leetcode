class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& t) {
        sort(t.begin(),t.end());
        int c=0;
        for(int i=1;i<t.size();i++){
            int p1=t[i][0];
            int pr1=t[i-1][1];
            if(p1<pr1){
                c++;
                if(t[i-1][1]<t[i][1]){
                t[i][0]=t[i-1][0];
                t[i][1]=(t[i-1][1]);
                }
              
            }

        }
        return c;
        
    }
};