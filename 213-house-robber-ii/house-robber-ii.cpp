class Solution {
public:
    int fun(vector<int> v1){
        vector<int> v3(v1.size());
        if(v1.size()==1) return v1[0];

        if(v1.size()==2) return max(v1[0],v1[1]);
        v3[v1.size()-1]=v1[v1.size()-1];
        v3[v1.size()-2]=v1[v1.size()-2];
         int max1=-1;

        for(int i=v1.size()-3;i>=0;i--){
             max1=-1;
            for(int j=i+2;j<v1.size();j++){
                max1=max(max1,v1[i]+v3[j]);
            }
            v3[i]=max1;

        }
        max1=*max_element(v3.begin(),v3.end());
        return max1;
    }
    int rob(vector<int>& n) {
        if(n.size()==1) return n[0];
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<n.size()-1;i++){
            v1.push_back(n[i]);
        }
        for(int i=1;i<n.size();i++){
            v2.push_back(n[i]);
        }

        return max(fun(v1),fun(v2));
        
    }
};