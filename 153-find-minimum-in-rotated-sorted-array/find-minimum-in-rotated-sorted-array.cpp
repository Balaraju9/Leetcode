class Solution {
public:
    int findMin(vector<int>& n) {
        if(n.size()==1) return  n[0];
        for(int i=0;i<n.size()-1;i++){
            if(n[i]>n[i+1]){
                return n[i+1];
            }
        }
        return n[0];
        
    }
};