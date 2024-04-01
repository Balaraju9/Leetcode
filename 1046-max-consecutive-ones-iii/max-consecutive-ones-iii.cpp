class Solution {
public:
    int longestOnes(vector<int>& n, int k) {
        int i=0,j=0,c=0,max1=0;
        while(j<n.size()){
            if(n[j]==0){
                c++;
            }
            while(c>k){
                if(n[i]==0){
                    c--;
                }
                i++;
            }
            max1=max(max1,(j-i)+1);
            j++;
        }
        return max1;
        
    }
};