class Solution {
public:
    int xorAllNums(vector<int>& n1, vector<int>& n2) {
   int z=0;
   if(n2.size()&1){
    for(int i=0;i<n1.size();i++){
        z^=n1[i];
    }

   }
   if(n1.size()&1){
    for(int i=0;i<n2.size();i++){
        z^=n2[i];
    }


   }
   return z;

        
    }
};