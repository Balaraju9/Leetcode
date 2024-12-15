class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v2;
        vector<int> v1;
        while (n--) {
            if (v2.size() == 0) {
                v1.push_back(1);
                v2.push_back(v1);
                v1.clear();
            } else if (v2.size() == 1) {
              v1.push_back(1);
              v1.push_back(1);
                v2.push_back(v1);
                v1.clear();
            } else {
                vector<int> ba = v2[v2.size() - 1];
                v1.push_back(ba[0]);
                for (int i = 1; i < ba.size(); i++) {
                    v1.push_back(ba[i] + ba[i - 1]);
                }
                v1.push_back(ba[ba.size() - 1]);
                v2.push_back(v1);
                v1.clear();
            }
        }
        return v2;
    }
};