class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int i=0,j=0,min1=0,max1=0;

        unordered_map<char,int> mp;
        mp['T']++;
        mp['F']++;
        mp['T']--;
        mp['F']--;
        while(j<a.size()){
            mp[a[j]]++;
            min1=min(mp['T'],mp['F']);
            while(k-min1<0 && i<=j&&j<a.size()){
                mp[a[i]]--;
                 min1=min(mp['T'],mp['F']);
                i++;
            }
            max1=max(max1,(j-i)+1);
            j++;
        }
        return max1;
        
    }
};