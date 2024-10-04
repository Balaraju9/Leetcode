class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(),s.end());
        long long s1=0;
        vector<long long> v1;
        for(long long i=0;i<s.size()/2;i++){
            s1+=s[i]*s[s.size()-i-1];
            v1.push_back(s[i]+s[s.size()-i-1]);
           


        }
        int fi=v1[0];
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=fi){
                return -1;
            }
        }
        return s1;
        
    }
};