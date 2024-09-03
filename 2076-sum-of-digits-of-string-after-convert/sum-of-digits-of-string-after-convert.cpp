class Solution {
public:
    string fun(string s1){
        int k=0;
        for(int i=0;i<s1.size();i++){
            k+=s1[i]-'0';
        }
        s1=to_string(k);
        return s1;
    }
    int getLucky(string s, int k) {
        cout<<s[0]-'0' - 48;
        string s1;
        for(int i=0;i<s.size();i++){
            s1+=to_string(s[i]-'0'-48);


        }
        while(k--){
            s1=fun(s1);

        }
        int pu=stoi(s1);
        return pu;
        
    }
};