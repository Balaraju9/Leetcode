class Solution {
public:
    int waysToSplitArray(vector<int>& n) {
        vector<long long int> v1(n.size());
        vector<long long int> v2(n.size());
        long long int s=0;
        for(int i=0;i<n.size();i++){
            s=s+n[i];
            v1[i]=s;
        }
        s=0;
        for(int i=n.size()-1;i>=0;i--){
            s=s+n[i];
            v2[i]=s;
        }
        long long int c=0;
        for(int i=0;i<v1.size()-1;i++){
            if(v1[i]>=v2[i+1]){
                c++;
            }
        }
        return c;
    }
};