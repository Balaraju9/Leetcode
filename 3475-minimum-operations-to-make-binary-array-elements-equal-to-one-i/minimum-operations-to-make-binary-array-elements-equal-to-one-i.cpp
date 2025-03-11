class Solution {
public:
    int minOperations(vector<int>& n) {
        int pu=0;
        for(int i=0;i<n.size()-2;i++){
            if(n[i]==0){
                pu++;
                for(int j=i;j<=i+2;j++){
                    if(n[j]==0){
                        n[j]=1;
                    }
                    else{
                        n[j]=0;
                    }
                }
            }
        }
        for(auto &i:n){
            if(i==0) return -1;

        }
        return pu;
        
    }
};