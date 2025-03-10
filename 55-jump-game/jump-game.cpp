class Solution {
public:
    bool canJump(vector<int>& n) {
        if(n.size()<=1){
            return true;
        }
        vector<bool> v1(n.size(),false);
        int reach=n.size()-1;
        for(int i=n.size()-1;i>=0;i--){
            if(i+n[i]>=reach){
                v1[i]=true;
                reach=i;


            }
        }
        return v1[0];
        
    }
};