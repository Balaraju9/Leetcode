class Solution {
public:
    int findLucky(vector<int>& ar) {
        int max1=-1;
        map<int,int> mp;
        for(int i=0;i<ar.size();i++){
            mp[ar[i]]++;
        }
        for(auto &i:mp){
            if(i.first==i.second){
                max1=max(i.second,max1);
            }
        }
        return max1;
        
    }
};