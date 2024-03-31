class Solution {
public:
    int longestSubarray(vector<int>& n) {
        int i=0,j=0,c=0,max1=0;
        while(j<n.size()){
            if(n[j]==0){
                c++;
            }
            while(c>1){
                if(n[i]==0){
                    c--;
                }
                i++;

            }
            max1=max(max1,(j-i));
            j++;


        }
        return max1;
        
    }
};