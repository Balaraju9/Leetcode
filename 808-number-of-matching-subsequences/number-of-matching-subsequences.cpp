class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
        unordered_map<char,vector<int>> mp;
       for(int i=0;i<s.size();i++){
        mp[s[i]].push_back(i);
       }
       int c=0;
       for(auto &i:w){
        string s1=i;
        int last=-1;
        for(int i=0;i<s1.size();i++){
            if(mp.find(s1[i])!=mp.end()){
                auto it=upper_bound(mp[s1[i]].begin(),mp[s1[i]].end(),last);
                if(it==mp[s1[i]].end()){
                    last=-1;
                    break;
                }
                last=*it;

            }
            else{
                last=-1;
                break;
            }
        }
        if(last!=-1){
            c++;
        }
       }
return c;
        
    }
};