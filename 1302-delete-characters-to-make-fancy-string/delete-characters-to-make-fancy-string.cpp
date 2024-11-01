class Solution {
public:
    string makeFancyString(string s) {
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s1.size()>=2){
                if(s1[s1.size()-1]==s[i] && s1[s1.size()-2]==s[i]){

                }
                else{
                    s1+=s[i];
                }

            }
            else{
                s1+=s[i];
            }
        }
        string s2="";
         for(int i=s.size()-1;i>=0;i--){
            if(s2.size()>=2){
                if(s2[s2.size()-1]==s[i] && s2[s2.size()-2]==s[i]){

                }
                else{
                    s2+=s[i];
                }

            }
            else{
                s2+=s[i];
            }
        }
        reverse(s2.begin(),s2.end());
        if(s1.size()>s2.size()){
            return s1;
        }
        return s2;
        
    }
};