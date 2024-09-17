class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s3) {
        unordered_map<string,int> mp;
        string s2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=' '){
                s2+=s1[i];
            }
            else{
                mp[s2]++;
                s2="";
            }

        }
        mp[s2]++;
        s2="";
                for(int i=0;i<s3.size();i++){
            if(s3[i]!=' '){
                s2+=s3[i];
            }
            else{
                mp[s2]++;
                s2="";
            }

        }
        mp[s2]++;
        vector<string> v1;
        for(auto &i:mp){
          if(i.second==1){
            v1.push_back(i.first);
          }

        }
        return v1;
        
    }
};