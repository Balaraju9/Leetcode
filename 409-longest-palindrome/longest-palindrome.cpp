class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &i:s){
            mp[i]++;
        }
        int z=0;
        int max1=0;
        for(auto &i:mp){
            if(i.second%2!=0){
                if(max1<i.second){
                    if(max1>0){
                    z=z+max1-1;
                    }
                    max1=i.second;
                }
                else{
                    z=z+i.second-1;
                    
                }
            }
            else if(i.second%2==0){
                z=z+i.second;
            }
        }
        return z+max1;;
        
    }
};