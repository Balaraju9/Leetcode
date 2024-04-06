class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string s1;
        int c=0;
        map<int,int> mp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                c++;
            }
            else if(s[i]==')'){
                c--;
            }
            if(c==-1){
                mp[i]++;
                c=0;
            }
        }
       
        s1="";
        c=0;
    for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                c++;
            }
            else if(s[i]=='('){
                c--;
            }
            if(c==-1){
                mp[i]++;
                c=0;
            }
        }
      for(int i=0;i<s.size();i++){
        if(mp.find(i)!=mp.end()){
            continue;
        }
        else{
            s1+=s[i];
        }
      }
        
        return s1;
    }
};