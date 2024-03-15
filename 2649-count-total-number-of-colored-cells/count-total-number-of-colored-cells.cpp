class Solution {
public:
    long long coloredCells(int n) {
          ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
       vector<long long> v1;
       v1.push_back(1);
       
       int i=1;

       while(n--){
        v1.push_back(4*i);
        i++;

       
       }
       for(int i=1;i<v1.size();i++){
        v1[i]=v1[i-1]+v1[i];
       }
       return v1[v1.size()-2];
    }
};