class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& sc, int k) {
        vector<int> v1;
        for(int i=0;i<sc.size();i++){
            v1.push_back(sc[i][k]);
        }
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1.size();j++){
                if(v1[i]>v1[j]){
                    int t=v1[i];
                    v1[i]=v1[j];
                    v1[j]=t;
                    vector<int> t1=sc[i];
                    sc[i]=sc[j];
                    sc[j]=t1;

                }
            }
        }
        return sc;
    }
};