class Solution {
public:
    vector<int> sortedSquares(vector<int>& n) {
        for(int i=0;i<n.size();i++){
            n[i]=n[i]*n[i];
        }
        int l=0,h=n.size()-1;
        vector<int> v1;
        while(l<=h){
            if(n[l]>=n[h]){
                v1.push_back(n[l]);
                l++;

            }
            else{
                v1.push_back(n[h]);
                h--;

            }
        }
        int i=0,j=v1.size()-1;
        while(i<=j){
            swap(v1[i],v1[j]);
            i++;
            j--;
        }
        return v1;
        
    }
};