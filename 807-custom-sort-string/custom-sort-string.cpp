class Solution {
public:
    string customSortString(string o, string s) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        map<int,char> mp;
        map<char,int> mp1;
        string s2="";
        for(int i=0;i<o.size();i++){
            mp[i]=o[i];
        }
        for(int i=0;i<s.size();i++){
            if(o.find(s[i])==string::npos){
                s2+=s[i];
            }
        }
        cout<<s2;
        for(int i=0;i<s.size();i++){
           
                mp1[s[i]]++;
            

        }
         
        vector<pair<char,int>> v1;
        for(auto &i:mp){
            for(auto &j:mp1){
                if(i.second==j.first){
                    v1.push_back(pair<char,int>{j.first,j.second});
                }

            }
        }
        string s1="";
       for(auto &i:v1){
           while(i.second!=0){
               s1+=i.first;
               i.second--;
           }
       }
       s1+=s2;
        return s1;
     

       
       

        
    }
};