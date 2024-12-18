class Solution {
public:
    int rob(vector<int>& n) {
        if(n.size()==1) return n[0];
        
        if(n.size()==2) return max(n[0],n[1]);
        vector<long long int> v1(n.size());
        v1[v1.size()-1]=n[n.size()-1];
        v1[v1.size()-2]=n[n.size()-2];
        long long int max1=0;
        for(long long int i=n.size()-3;i>=0;i--){
            long long int min1= INT_MIN;
            for(long long int j=i+2;j<v1.size();j++){
                min1=max(min1,v1[j]+n[i]);
            }
            v1[i]=min1;
            max1=max(max1,v1[i]);
        }
        int pu11=*max_element(v1.begin(),v1.end());
       if(pu11>max1) return pu11;
        return max1;        
    }
};