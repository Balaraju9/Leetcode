class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_map<string,string> mp;
        for(auto &i:d){
            mp[i]=i;

        }
         vector<string> v1;
    string z="";
    string pu="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            z+=s[i];
        }
        else{
            v1.push_back(z);
            z="";

        }
    }
    if(z.size()!=0){
        v1.push_back(z);
    }
     for(int i=0;i<v1.size();i++){
        for(int j=0;j<v1[i].size();j++){
            pu+=v1[i][j];
            if(mp.find(pu)!=mp.end()){
                v1[i]=mp[pu];
                break;
            }

        }
        pu="";
     }
     pu="";
    
    for(int i=0;i<v1.size();i++){
        if(i<v1.size()-1){
        pu+=v1[i]+" ";
        }
        else{
            pu+=v1[i];
        }
    }
    return pu;
    }
};
