class Solution {
public:
    int minOperations(int n) {
        int s=0;
        vector<int> ar;
        for(int i=0;i<n;i++){
            ar.push_back((2*i)+1);
        }
        int k=(ar[0]+ar[ar.size()-1])/2;
        for(int i=0;i<n/2;i++){
            s+=k-ar[i];
        }
        return s;

        
    }
};