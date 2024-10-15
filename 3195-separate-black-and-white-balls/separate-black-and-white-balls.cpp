class Solution {
public:
    long long minimumSteps(string s) {
        long long i=0,j=s.size()-1;
        long long ans=0;
        while(i<j && i<s.size() && j>=0){
            while( i<s.size() && s[i]=='0' ){
                i++;
            }

            while(j>=0 && s[j]=='1'  ){
                j--;
            }
            if(i==j || j<i){
                break;
            }
            ans+=abs(j-i);
           i++;
           j--;
              if(i==j || j<i){
                break;
            }
        }
        return ans;
        
    }
};