class Solution {
public:
    bool isv(char i){
        if(i=='i' ||i=='a'||i=='e'||i=='o'||i=='u'){
            return true;
        }
        return false;
    }
    long long fun(string w,int k){
        unordered_map<char,int> mp;
        long long int i=0,j=0,cons=0,ans=0;
        while(j<w.size()){
            if(isv(w[j])){
                mp[w[j]]++;
            }
            else{
                cons++;
            }
            while(mp.size()==5 && cons>=k ){
                ans+=w.size()-j;
                if(isv(w[i])){
                    mp[w[i]]--;
                    if(mp[w[i]]==0){
                           
                            mp.erase(w[i]);
                    }
                }
                else{
                    cons--;
                }
                    i++;
            }
            j++;

        }
        return ans;
    }
    long long countOfSubstrings(string w, int k) {
        return fun(w,k)-fun(w,k+1);
        
    }
};