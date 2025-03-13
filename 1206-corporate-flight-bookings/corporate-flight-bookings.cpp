class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> v1(n);
        for(int i=0;i<b.size();i++){
            int j=b[i][1];
            v1[b[i][0]-1]+=b[i][2];
            if(j<n){
                v1[j]+=(-1*b[i][2]);
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            s+=v1[i];
            v1[i]=s;

        }
        return v1;
        
    }
};