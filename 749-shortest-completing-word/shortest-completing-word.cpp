class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& w) {
        string s1="";
        for(int i=0;i<l.size();i++){
            if(l[i]>='a' && l[i]<='z'){
                s1+=l[i];
            }
                        if(l[i]>='A' && l[i]<='Z'){
                s1+=tolower(l[i]);
            }


        }
        sort(s1.begin(),s1.end());
       
        unordered_map<char,int> mp;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        int z=0;
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        vector<string> v4;
        unordered_map<char,int> mp1=mp;
        int min=10000,i=0,j=0;
        for(i=0;i<w.size();i++){
            string s2="";
            for(j=0;j<w[i].size();j++){
                if(mp1.find(w[i][j])!=mp1.end()){
                  s2+=w[i][j];
                   
                }
                
            
            }
             
           
           sort(s2.begin(),s2.end());
           if(s2.size()>=s1.size()){
               v2.push_back(w[i]);

                
                v1.push_back(s2);
           }
                
            
            
           
            
        }
        int k=0;
        int b=0;
       for(k=0;k<v1.size();k++){
           mp1=mp;
           z=0;
           for(b=0;b<v1[k].size();b++){
               if(mp1[v1[k][b]]!=0){
                   mp1[v1[k][b]]--;
               }
           }
           for(auto &i:mp1){
               if(i.second==0){
                   z++;
               }
           }
           if(z==mp.size()){
               v3.push_back(v1[k]);
               v4.push_back(v2[k]);
           }
       }
      
       if(v3.size()==1){
           return v4[0];
       }
       string ba="";
       for(auto &i:v4){
           if(i.size()<min){
               min=i.size();
               ba=i;
           }
       }
       return ba;
       


        
    }
};