class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> mp;
         unordered_map<char,int> mp1;

        vector<int> v1(s.size());
        for(int i=s.size()-1;i>=0;i--){
            if(mp.find(s[i])==mp.end()){
                v1[i]=-1;
            }
            else{
                v1[i]=mp[s[i]];
                
            }
            mp[s[i]]=i;
            mp1[s[i]]++;
        }
       
        unordered_map<string,int> mp4;
        int c=0;
        for(int i=0;i<s.size();i++){
            if((v1[i]-i)+1>=3){

                for(int j=i+1;j<=v1[i]-1;j++){
                    string s3="";
                    s3+=s[i];
                    s3+=s[j];
                    s3+=s[i];
                    mp4[s3]++;
                    

                }
                
            }
        }
        for(auto &i:mp1){
            if(i.second>=3){
                 string s3="";
                    s3+=i.first;
                    s3+=i.first;
                    s3+=i.first;
                
                    mp4[s3]++;
            }
        }
        return mp4.size();

        
    }
};