class Solution {
public:
    vector<int> partitionLabels(string s) {
            vector<int> v1(s.size());
            unordered_map<char,int> mp;
            for(int i=s.size()-1;i>=0;i--){
                if(mp.find(s[i])!=mp.end()){
                    v1[i]=mp[s[i]];
                }
                else{
                    v1[i]=i;
                    mp[s[i]]=i;
                }
            }
           
            mp.clear();
            int max1=0;
            int i=0,lastind=0;
            vector<int> ans;
         while(i<s.size()){
            max1=max(max1,v1[i]);
            if(max1==i){
                ans.push_back(i-lastind+1);
                lastind=i+1;
            }

           
                i++;


         }
            return ans;
        
    }
};