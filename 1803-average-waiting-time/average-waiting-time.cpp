class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {

        double k=0,k1=0;
        for(int i=0;i<c.size();i++){
            if(i==0){
                k=c[i][0]+c[i][1];

            }
            else if(k>=c[i][0]){
                k+=c[i][1];

            }
            else{
                k=(c[i][0]+c[i][1]);
            }
           
            k1+=(k-c[i][0]);
        }
        return k1/c.size();

        
    }
};