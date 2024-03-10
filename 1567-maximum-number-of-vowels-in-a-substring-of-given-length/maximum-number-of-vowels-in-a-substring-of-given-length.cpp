class Solution {
public:
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int i=0,j=0,max1=0,c=0;
        string s1="aeiou";
        while(j<s.size()){
            if(s1.find(s[j])!=string::npos){
                c++;
            }
            if(((j-i)+1)<k){
                j++;
            }
            else{
                max1=max(max1,c);
                if(s1.find(s[i])!=string::npos){
                    c--;

                }
                i++;
                j++;

            }
        }
        return max1;
    }
};