class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2) {
        int i=0,j=0,c=-9786;

        while(i<n1.size()&&j<n2.size()){
            if(n1[i]==n2[j]){
                c=n1[i];
                break;
            }
            else if(n1[i]>n2[j]){
                j++;

            }
            else{
                i++;
            }

        }
        if(c!=-9786){
            return c;
        }
        return -1;

        
    }
};