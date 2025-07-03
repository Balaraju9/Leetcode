class Solution {
public:
    string fun(string s){
        string ans;
        for(int i=0;i<s.size();i++){
            int ind=s[i]-'a';
            ind++;
            if(ind==27){
                ind=0;
            }
            char ch=ind+'a';
            ans+=ch;
        }
        return ans;
    }
    char kthCharacter(int k) {
        string s1="a";

        while(s1.size()<k){
            string s2=fun(s1);
            s1=s1+s2;

        }
        return s1[k-1];
        
    }
};