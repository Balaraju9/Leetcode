class Solution {
public:
    int maxSum(vector<int>& n) {
        vector<int> v1;
        int r=0,s=0;
        for(int i=0;i<n.size();i++){
            int t=n[i];
            s=0;
            if(t>9){
                while(t!=0){
                    r=t%10;
                    s=max(s,r);
                    t=t/10;
                }
                v1.push_back(s);

            }
            else{
                v1.push_back(n[i]);
            }
        }
        int max1=-1;
        for(auto &i:v1){
            cout<<i<<" ";
        }
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n.size();j++){
                if(i<j && v1[i]==v1[j]){
                    max1=max(max1,(n[i]+n[j]));
                }
            }
        }
        return max1;

        
    }
};