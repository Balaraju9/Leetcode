class Solution {
public:
    vector<int> topKFrequent(vector<int>& n, int k) {
        unordered_map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>> p;
        for(auto &i:n){
            mp[i]++;

        }
        for(auto &i:mp){
            int a1=i.first;
            int b1=i.second;
            p.push(b1);
            if(p.size()>k){
                p.pop();
            }
        }
        set<int> s;
        while(!p.empty()){
            s.insert(p.top());
          
            p.pop();
        }
        vector<int> ans;
        for(auto &i:mp){
            if(s.find(i.second)!=s.end()){
                ans.push_back(i.first);
            }
        }
return ans;
        return {};

        
    }
};