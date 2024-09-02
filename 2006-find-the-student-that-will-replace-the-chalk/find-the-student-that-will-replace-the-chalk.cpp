class Solution {
public:
    int chalkReplacer(vector<int>& ch, int k) {
        long long c=0;
        for(long long i=0;i<ch.size();i++){
            c+=ch[i];
        }
        while(c<=k){
            k=k-c;
        }
       for(int i=0;i<ch.size();i++){
        k=k-ch[i];
        if(k<0){
            return i;
        }
        
       }
       return 0;
    }
};