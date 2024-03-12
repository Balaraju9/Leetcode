class Solution {
public:
    int triangularSum(vector<int>& n) {
        vector<int> v1;

        while(n.size()!=1){
            for(int i=0;i<n.size()-1;i++){
                int k=n[i]+n[i+1];
                v1.push_back(k%10);

            }
            n=v1;
            v1.clear();
        }
        return n[0];
        
    }
};