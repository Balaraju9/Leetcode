class Solution {
public:
    int fun(int l,int h,int t,vector<int>& n){
        while(l<=h){
            int m=(l+h)/2;
            if(n[m]==t){
                return m;
            }
            else if(t>n[m]){
                l=m+1;
            }
            else{
                h=m-1;
            }

        }
        return -1;
    }

    int search(vector<int>& n, int t) {
        if(n.size()==1){
            if(n[0]==t) return 0;
            return -1;
        }
        for(int i=0;i<n.size();i++){
            if(i>0 && n[i]<n[i-1]){
                int k=fun(0,i-1,t,n);
                if(k==-1){
                     k=fun(i,n.size()-1,t,n);
                }
                return k;


            }
            else if(n[i]==t){
                return i;
            }
        }
        return -1;
        
    }
};