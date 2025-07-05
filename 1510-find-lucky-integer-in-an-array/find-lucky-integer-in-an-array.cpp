class Solution {
public:
    int findLucky(vector<int>& arr) {
        int hehe =-1;
        sort(arr.begin(),arr.end());

        for(int i=1;i<arr.size();i++){
            int cnt = 1;
            while(i<arr.size() && arr[i]==arr[i-1]){
                cnt++;
                ++i;
            }
            if(cnt==arr[i-1]){
                hehe = arr[i-1];
            }
        }
        return hehe;
    }
};