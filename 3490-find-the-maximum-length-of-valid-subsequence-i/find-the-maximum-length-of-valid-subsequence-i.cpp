class Solution {
public:
    int maximumLength(vector<int>& n) {
        if(n.size()<=2) return n.size();
        int even=0,odd=0;
        for(auto &i:n){
            if(i%2==0){
                even++;

            }
            else{
                odd++;

            }
        }
        int ce=0,al=0;
        for(auto &i:n){
            if(ce==0 && i%2==0){
                al++;
                ce=1;

            }
            if(ce==1 && i%2!=0){
                al++;
                ce=0;
            }
           
        }
           int ce1=1,al1=0;
        for(auto &i:n){
            if(ce1==0 && i%2==0){
                al1++;
                ce1=1;

            }
            if(ce1==1 && i%2!=0){
                al1++;
                ce1=0;
            }
           
        }
        int max1;
        max1=max(al,even);
        max1=max(max1,odd);
        max1=max(max1,al1);
        return max1;
        
    }
};