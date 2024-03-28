class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,s1=0;
        unordered_map<char,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==3){
                
            while(mp.size()==3){
                s1=s1+(s.size()-j);
                

                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
           
            }
            j++;
            
        }
        return s1;
        
    }
};