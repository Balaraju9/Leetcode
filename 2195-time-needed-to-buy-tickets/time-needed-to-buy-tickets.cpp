class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int c=0;
        while(t[k]>0){
            for(int i=0;i<t.size();i++){
                if(t[i]>0){
                    c++;
                }
                t[i]--;
                if(t[k]==0){
                    break;
                }
            }
        }
        return c;
        
    }
};