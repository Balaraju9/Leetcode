class Solution {
public:
bool fun(string ba,string manu){
    int i=0;
    int j=0;
    while(j<manu.size()){
        if(ba[i]==manu[j]){
            i++;
            j++;
        }
        else{
            return false;
        }
        
    }
    return true;
}
    int prefixCount(vector<string>& w, string p) {
        int z=p.size();
        int c=0;
        for(int i=0;i<w.size();i++){
            if(w[i].size()>=z){
                if(fun(w[i],p)){
                    c++;
                }
            }
        }
        return c;
        
    }
};