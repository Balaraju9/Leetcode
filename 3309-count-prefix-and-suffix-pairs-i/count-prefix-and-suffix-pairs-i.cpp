class Solution {
public:
    bool issuff(string i,string j){
        if(i.size()<=j.size()){
            for(int pu=0;pu<i.size();pu++){
                if(i[pu]!=j[pu]){
                    return false;
                }
            }
            int i1=i.size()-1;
            
            for(int pu=j.size()-1;pu>=0;pu--){
                if(i1>=0 && j[pu]!=i[i1]){
                    return false;
                }
                i1--;

            }
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& w) {
        int c=0;
        for(int i=0;i<w.size();i++){
            for(int j=i+1;j<w.size();j++){
                if(i!=j){
                    if(issuff(w[i],w[j])) c++;
                }
            }
        }
        return c;

        
    }
};