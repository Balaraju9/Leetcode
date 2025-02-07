class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& q) {
        unordered_map<int,int> bal;
        unordered_map<int,int> col;
        vector<int> v1(q.size());
        for(int i=0;i<q.size();i++){
            if(bal.find(q[i][0])!=bal.end()){
                col[bal[q[i][0]]]--;
                if(col[bal[q[i][0]]]==0){
                    col.erase(bal[q[i][0]]);
                }
            }
            
                bal[q[i][0]]=q[i][1];
                col[q[i][1]]++;
            
            v1[i]=col.size();
        }
        return v1;

        
    }
};