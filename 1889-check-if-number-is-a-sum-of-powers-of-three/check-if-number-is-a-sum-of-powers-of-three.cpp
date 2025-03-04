class Solution {
public:
    bool checkPowersOfThree(int n) {
        int pu=1;
        vector<int> v1;

        while(true){
            if(pu>n){
                break;

            }
            else{
                v1.push_back(pu);
                pu=pu*3;
                
            }
        }
        int z=0;
        for(int i=0;i<pow(2,v1.size());i++){
            z=0;
            for(int j=0;j<v1.size();j++){
                if(i&(1<<j)){
                    z+=v1[j];
                    if(z>n){
                        break;
                    }
                    
                }

            }
            if(z==n) return true;
        }
        return false;

        
    }
};