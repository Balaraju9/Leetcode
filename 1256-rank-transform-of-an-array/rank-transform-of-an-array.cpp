class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ar1=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int c=1;
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==0){
                mp[arr[i]]=c;
                c++;
                
            }
            else{
                continue;
            }
        }
        for(int i=0;i<ar1.size();i++){
            ar1[i]=mp[ar1[i]];
        }

        return ar1;

        
    }
};