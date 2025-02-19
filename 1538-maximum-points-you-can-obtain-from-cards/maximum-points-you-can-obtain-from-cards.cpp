class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        vector<int> v1;
       for(int i=k-1;i>=0;i--){
        v1.push_back(c[i]);

       }
       for(int i=c.size()-1;i>c.size()-k-1;i--){
        v1.push_back(c[i]);
       }
    
      int i=0,j=0,s=0,mac=0;
      while(j<v1.size()){
        s+=v1[j];
        while((j-i)+1>k){
            s-=v1[i];
            i++;
        }  
        if((j-i)+1==k){
            mac=max(mac,s);
        }
        j++;
            }
            return mac;
        
    }
};