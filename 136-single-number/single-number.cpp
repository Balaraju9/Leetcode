class Solution {
public:
    int singleNumber(vector<int>& n) {
        int pu=0;
        for(auto &i:n){
           
                pu=pu^i;
            


        }
return pu;        
    }
};