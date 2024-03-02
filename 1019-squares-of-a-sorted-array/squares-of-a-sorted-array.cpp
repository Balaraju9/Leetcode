class Solution {
public:
    vector<int> sortedSquares(vector<int>& n) {
        int k=n.size();
        for(int i=0;i<n.size();i++){
            if(n[i]==0){
                k=i;
                break;
            }
            else if(n[i]>0){
                k=i;
                break;
            }
        }
       
        int j=k-1;
        vector<int> v1;
        while(j>-1 && k<n.size()){
            if((n[j]*n[j])>(n[k]*n[k])){
                v1.push_back(n[k]*n[k]);
                k++;
            }
            else{
                v1.push_back(n[j]*n[j]);
                j--;
            }
        }
while(k<n.size()){
         
                v1.push_back(n[k]*n[k]);
                k++;
            
           
        }
while(j>-1 ){
           
            
                v1.push_back(n[j]*n[j]);
                j--;
            

        }
       
        
       
        return v1;
        
    }
};