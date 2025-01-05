class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        vector<int> v1(s.size(),0);
        for(auto &i:sh){
            vector<int> pu=i;
            int st=pu[0];
            int end=pu[1];
            if(pu[2]==0){
                if(end==s.size()-1){
                    v1[st]=v1[st]-1;
                }
                else{
                    v1[st]=v1[st]-1;
                    v1[end+1]=v1[end+1]+1;
                }


            }
            else{
                if(end==s.size()-1){
                    v1[st]=v1[st]+1;
                }
                else{
                    v1[st]=v1[st]+1;
                    v1[end+1]=v1[end+1]-1;
                }

            }
        }
       for(int i=1;i<v1.size();i++){
        v1[i]=v1[i]+v1[i-1];
       }
        for(int i=0;i<s.size();i++){
            if(v1[i]>=1){
                int balu=((s[i]-'a')+v1[i])%26;
               
                s[i]=balu+'a';

            }
            else if(v1[i]<0){
                 int balu=((s[i]-'a')+v1[i])%26;
                  
                 if(balu<0){
                    balu=balu+26;
                 }
                s[i]=balu+'a';

            }
            
        }
        return s;
        
    }
};