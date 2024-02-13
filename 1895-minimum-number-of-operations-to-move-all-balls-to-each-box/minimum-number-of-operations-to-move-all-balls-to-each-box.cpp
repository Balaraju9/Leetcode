#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string n) {
        vector<int> v1;

        for (auto &i : n) {
            v1.push_back(int(i) - 48);
        }

        vector<int> v2 = v1;
        int s = 0;

        for (int i = 0; i < v1.size(); i++) {
            s = 0;
            for (int j = i+1; j < v1.size(); j++) {
                if (v1[j] == 1) {
                    s += abs(i - j);
                }
            }
            v1[i] = s;
        }

        reverse(v2.begin(), v2.end());
        int s1 = 0;

        for (int i = 0; i < v2.size(); i++) {
            s1 = 0;
            for (int j = i+1; j < v2.size(); j++) {
                if (v2[j] == 1) {
                    s1 += abs(i - j);
                }
            }
            v2[i] = s1;
        }

        reverse(v2.begin(), v2.end());

        vector<int> result;

        for (int i = 0; i < v1.size(); i++) {
            result.push_back(v1[i] + v2[i]);
        }

        return result;
    }
};