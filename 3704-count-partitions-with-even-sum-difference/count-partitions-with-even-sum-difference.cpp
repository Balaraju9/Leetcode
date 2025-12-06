class Solution {
public:
    int countPartitions(vector<int>& n) {
        vector<int> v1(n.size());
        vector<int> v2(n.size());
        int s1=0,s2=0;
        for(int i=0;i<n.size();i++){
            s1+=n[i];
            s2+=n[n.size()-i-1];
            v1[i]=s1;
            v2[v2.size()-i-1]=s2;

        }
        int c=0;
       for(int i=1;i<v1.size();i++){
        
        if(abs(v1[i-1]-v2[i])%2==0){
            c++;
        }
       }
        return c;
        
        
    }
};