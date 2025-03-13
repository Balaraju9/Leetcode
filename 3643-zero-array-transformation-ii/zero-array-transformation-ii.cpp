class Solution {
public:
    bool fun(int mind,vector<int> &n, vector<vector<int>>& q){
        vector<int> v1(n.size());
        for(int i=0;i<mind;i++){
            int i1=q[i][0];
            int j1=q[i][1];
            int z1=q[i][2];
            v1[i1]+=z1;
            if(j1+1<n.size()){
                v1[j1+1]-=z1;
            }

        }
        int s=0;
        for(int i=0;i<v1.size();i++){
            s+=v1[i];
            v1[i]=s;
        }
       
        for(int i=0;i<n.size();i++){
            if(n[i]>v1[i]){
                return false;
            }
        }
        return true;

    }
    int minZeroArray(vector<int>& n, vector<vector<int>>& q) {
        int l=0,h=q.size();
        int m=0;
          if (!fun(q.size(), n, q)) return -1;
        while(l<=h){
            m=(l+h)/2;
            if(fun(m,n,q)==true){
                h=m-1;
            }
            else{
                l=m+1;
            }

        }
        
        return l;
        
    }
};
