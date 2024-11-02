class Solution {
public:
    bool isCircularSentence(string s) {
        vector<string> v1;
        string s1="";
        for(int i=0;i<s.size();i++){
            while(i<s.size() && s[i]!=' '){
                s1+=s[i];
                i++;
            }
             if (!s1.empty()) {
                string pu = string(1, s1[0]) + string(1, s1[s1.size() - 1]);
                v1.push_back(pu);
            }
            s1="";

        }
        if(v1.size()==1){
            if(v1[0][0]!=v1[0][1]){
                return false;
            }
            return true;
            
        }
        for(int i=0;i<v1.size()-1;i++){
            if(v1[i][1]==v1[i+1][0]){
                continue;
            }
            else{
                return false;
            }
            
        }
        if(v1[0][0]==v1[v1.size()-1][1]){
            return true;
        }
        return false;
    }
};