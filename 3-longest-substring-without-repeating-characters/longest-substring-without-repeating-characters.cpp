class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c=0,max1=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
     mp.clear();
            c=0;
            
            for(int j=i;j<s.size();j++){
                if(mp.find(s[j])==mp.end()){
                    c++;
                    mp[s[j]]++;
                    max1=max(max1,c);
                }
                else{
                    
                    break;
                }
            }
           
        }
        return max1;
        
    }
};