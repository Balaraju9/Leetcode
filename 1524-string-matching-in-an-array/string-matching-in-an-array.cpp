class Solution {
public:
    vector<string> stringMatching(vector<string>& w) {
        unordered_map<string,int> mp;
        for(int i=0;i<w.size();i++){
            string s1=w[i];
            for(int j=0;j<w.size();j++){
                if(i!=j && w[j].find(s1)!=string::npos){
                    mp[s1]++;
                }
            }
        }
        vector<string> v1;
        for(auto &i:mp){
            v1.push_back(i.first);

        }
        return v1;
    }
};