class Solution {
public:
bool fun(int &m,vector<int> &p,int h){
    int c=0;
    for(int i=0;i<p.size();i++){
        if(p[i]<=m){
            c++;

        }
        else if(p[i]%m==0){
            c=c+(p[i]/m);
        }
        else {
            c=c+(p[i]/m)+1;
        }
        if(c>h){
            return false;
        }
    }
    return true;
}
    int minEatingSpeed(vector<int>& p, int h) {
        sort(p.begin(),p.end());
        int cap=p[p.size()-1];
        int st=1;
        while(st<=cap){
            int m=(st+cap)/2;
            if(fun(m,p,h)){
                cap=m-1;
            }
            else{
                st=m+1;
            }
        }
       return st;
        
    }
};