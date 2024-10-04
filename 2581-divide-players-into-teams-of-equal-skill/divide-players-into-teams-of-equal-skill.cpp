class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(),s.end());
        long long s1=0;
       unordered_map<int,int> mp;
        for(long long i=0;i<s.size()/2;i++){
            s1+=s[i]*s[s.size()-i-1];
           mp[(s[i]+s[s.size()-i-1])]++;
           if(mp.size()>1){
            return -1;
           }
           


        }
        
        return s1;
        
    }
};