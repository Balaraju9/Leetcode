class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& n) {
        int c=0,max1=0;
        for(int i=0;i<n.size();i++){
            if(n[i]==1){
                c++;
            }
            else{
                c=0;
            }
            max1=max(max1,c);
        }
        return max1;
        
    }
};