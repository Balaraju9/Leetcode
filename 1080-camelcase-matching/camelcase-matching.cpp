class Solution {
public:
bool fun(string q, string p){
    int i=0,j=0;
    while(i<q.size() && j<p.size()){
        
        if(q[i]==p[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(j==p.size()){
            return true;
        }
    return false;
    

}
    vector<bool> camelMatch(vector<string>& q, string p) {
        vector<string> v1;
        unordered_map<string,int> mp;
        string c1="",c="";
        for(int i=0;i<p.size();i++){
            if(p[i]>='A'&&p[i]<='Z'){
                c+=p[i];
            }
        }
        for(int i=0;i<q.size();i++){
            for(int j=0;j<q[i].size();j++){
             if(q[i][j]>='A'&&q[i][j]<='Z'){
                c1+=q[i][j];
            }

            }
            if(c1==c){
                v1.push_back(q[i]);
            }
            c1="";
        }
        for(int i=0;i<v1.size();i++){
            if(fun(v1[i],p)){
                mp[v1[i]]++;
            }
        }
        vector<bool> v3;
        for(auto &i:q){
            if(mp.find(i)!=mp.end()){
                v3.push_back(true);
            }
            else{
                v3.push_back(false);
            }
        }
        return v3;
        
    }
};