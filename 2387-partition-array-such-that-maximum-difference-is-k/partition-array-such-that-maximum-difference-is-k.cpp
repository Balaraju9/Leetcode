class Solution {
public:
    int partitionArray(vector<int>& n, int k) {
        sort(n.begin(),n.end());
        int min1=n[0],c=0;

        for(int i=1;i<n.size();i++){
            if(n[i]-min1 >k){
                min1=n[i];
                c++;
            }

        }
        return c+1;
        
    }
};