class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& n, int k) {
        sort(n.begin(),n.end());
        vector<vector<int>> v1;
        vector<int> v2;
        int c=0;
        for(int i=0;i<n.size();i++){
            if(c==3){
                v1.push_back(v2);
                c=0;
                v2.clear();
            }
            v2.push_back(n[i]);
            c++;

        }
        v1.push_back(v2);
       
        
        for(int i=0;i<v1.size();i++){
            if((v1[i][1]-v1[i][0])<=k && (v1[i][2]-v1[i][1])<=k && (v1[i][2]-v1[i][0])<=k){
                continue;
            }
            else{
                return {};
            }
        }
        return v1;;
        
        
    }
};