class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        for(int i=0;i<k-1;i++){
            c.push_back(c[i]);
        }
        int l=0;
        int c1=0;
        for(int i=1;i<c.size();i++){
            if(c[i]==c[i-1]){
                l=i;
            }
            if(i-l+1>=k){
                c1++;
            }
        }
        return c1;
        
    }
};