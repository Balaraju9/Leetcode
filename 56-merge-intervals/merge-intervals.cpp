class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.size()==1){
            return arr;
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            if(arr[i-1][1]>=arr[i][0] && arr[i-1][1]<=arr[i][1]){
                arr[i][0]=arr[i-1][0];
                arr[i-1]={};
            }
            else if(arr[i-1][1]>arr[i][0] && arr[i-1][1]>arr[i][1]){
                arr[i]=arr[i-1];
                arr[i-1]={};
            }
        }
        vector<vector<int>> v2;
        for(auto &i:arr){
            if(i.size()>0){
                v2.push_back(i);
            }
        }
        return v2;

        
    }
};