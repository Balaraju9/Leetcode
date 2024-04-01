class Solution {
public:
    vector<int> pivotArray(vector<int>& n, int p) {
        vector<int> v1;
        for(int i=0;i<n.size();i++){
            if(n[i]<p){
                v1.push_back(n[i]);
            }
        }
        for(int i=0;i<n.size();i++){
            if(n[i]==p){
                v1.push_back(n[i]);
            }
        }
        for(int i=0;i<n.size();i++){
            if(n[i]>p){
                v1.push_back(n[i]);
            }
        }
        return v1;
        
        
    }
};