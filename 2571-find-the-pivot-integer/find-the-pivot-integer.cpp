class Solution {
public:
    int pivotInteger(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> v1;
        int s=0,s1=0;
        int i=0;
        for(i=1;i<=n;i++){
            v1.push_back(i);
            s+=i;
         
        }
       
        for(i=0;i<v1.size();i++){
            s=s-v1[i];
           
            if(s==s1){
                break;
            }
            s1+=v1[i];
           
        }
        
        
        if(i==v1.size()){
            return -1;
        }
        return i+1;
    }
};