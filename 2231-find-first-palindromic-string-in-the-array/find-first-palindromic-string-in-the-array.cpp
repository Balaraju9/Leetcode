class Solution {
public:
    string firstPalindrome(vector<string>& w) {
        for(int i=0;i<w.size();i++){
            
            string s1=w[i];
            reverse(w[i].begin(),w[i].end());
            if(s1==w[i]){
                return w[i];
            }
        }
        return "";
        
    }
};