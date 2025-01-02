class Solution {
public:
    bool fun(char ch){
        if(ch=='a' || ch=='e'|| ch=='i' || ch=='o'|| ch=='u' || ch=='A'|| ch=='E' || ch=='I'|| ch=='O' || ch=='U' ){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        vector<int> v1(w.size());
        int c=0;
        for(int i=0;i<w.size();i++){
            if(fun(w[i][0]) && fun(w[i][w[i].size()-1])){
                c++;
            }
            v1[i]=c;
        }
        vector<int> ans;
        for(auto &i:q){
            vector<int> pu=i;
            int k1=pu[0];
            int k2=pu[1];
            if(k1-1<0){
                ans.push_back(v1[k2]);

            }
            else{
                ans.push_back(v1[k2]-v1[k1-1]);
            }
        }
        return ans;
        
    }
};