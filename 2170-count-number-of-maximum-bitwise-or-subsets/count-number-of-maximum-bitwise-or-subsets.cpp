class Solution {
public:
    int countMaxOrSubsets(vector<int>& n) {
        int or1=0;
        int or2=0,c=0;
        for(int i=0;i<n.size();i++){
            or1|=n[i];
        }
        for(int i=0;i<pow(2,n.size());i++){
            or2=0;
            for(int j=0;j<n.size();j++){
                if(i&(1<<j)){
                    or2|=n[j];
                }
            }
            if(or1==or2){
                c++;
            }

        }
        return c;
    }
};