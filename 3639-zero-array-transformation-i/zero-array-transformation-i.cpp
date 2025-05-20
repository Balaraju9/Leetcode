class Solution {
public:
    bool isZeroArray(vector<int>& n, vector<vector<int>>& q) {
        vector<int> v1(n.size(),0);
        for(int i=0;i<q.size();i++){
            int p1=q[i][0];
            int p2=q[i][1]+1;
            v1[p1]=v1[p1]-1;
            if(p2<n.size()){
                v1[p2]+=1;
            }

        }
        int s=0;
        for(int i=0;i<v1.size();i++){
            s+=v1[i];
           if((s+n[i])>0) return false;
        }
      
        return true;
        
    }
};