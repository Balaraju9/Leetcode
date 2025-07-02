class Solution {
public:
    bool sup = false;
    void fun(int n, int s, int d,
             unordered_map<int, vector<int>>& mp1,
             unordered_map<int, int>& mp) {
        queue<int> q;
       q.push(s);
       
        while (!q.empty()) {
            int pu = q.front();
            q.pop();
           
            if (pu == d) {
                sup = true;
                return;
            }
            
                mp[pu] = 0;
                for (auto& i : mp1[pu]) {
                    if (mp[i] == 1) {
                        q.push(i);
                        mp[i] = 0;
                    }
                }
            
        }
    }
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        if(s==d) return true;
        unordered_map<int, vector<int>> mp1;
        unordered_map<int, int> mp;
        for (int i = 0; i < e.size(); i++) {
            int a1 = e[i][0];
            int b1 = e[i][1];
            mp1[a1].push_back(b1);
             mp1[b1].push_back(a1);

            mp[a1] = 1;
            mp[b1] = 1;
        }
        fun(n, s, d, mp1, mp);
        return sup;
    }
};