class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int i=0,j=0;
        int c=0;
        while(j<a.size()){
            
            if(a[j]%2!=0){
                c++;
            }
            while((j-i)+1>3 && i<a.size()){
                if(a[i]%2!=0){
                    c--;
                }
                i++;

            }
            if(c==3){
                return true;
            }
            j++;
           
        }
        return false;
        
    }
};