class Solution {
public:
    int strStr(string h, string n) {
        int i=0,j=0;
        int pu=0;
        for(int i=0;i<h.size();i++){
            if(h[i]==n[j]){
                pu=i;
                while(i<h.size() && j<n.size() && h[i]==n[j]){
                    i++;
                    j++;
                    
                }
                if(j==n.size()){
                    return i-(n.size());
                }
                else{
                    j=0;
                    i=pu;
                }

            }
        }
        return -1;
        
    }
};