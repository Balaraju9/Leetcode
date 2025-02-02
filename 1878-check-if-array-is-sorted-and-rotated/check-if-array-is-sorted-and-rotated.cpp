class Solution {
public:
    bool check(vector<int>& n) {
        int pu=-1;
        for(int i=0;i<n.size()-1;i++){
            if(n[i]<=n[i+1]){
                continue;
            }
            else{
                pu=i+1;
                break;
            }
        }
     
        if(pu==-1) return true;
        int co=n.size();
        int car=n[pu];
        while(co--){
            if(car<=n[pu]){
                car=n[pu];
            }
            else{
                return false;
            }
           
            pu++;
            pu=pu%n.size();

        }
       
        return true;

        
    }
};