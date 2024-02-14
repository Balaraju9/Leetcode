class Solution {
public:
    vector<int> rearrangeArray(vector<int>& n) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        for(int &i:n){
            if(i>0){
                v1.push_back(i);
            }
            else{
                v2.push_back(i);
            }
        }
        for(int i=0;i<n.size()/2;i++){
            v3.push_back(v1[i]);
            v3.push_back(v2[i]);
        }
        return v3;
        
    }
};