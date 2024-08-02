class Solution {
public:
    int minSwaps(vector<int>& n) {
        vector<int> v1;
        int c=0,min1=INT_MAX;
        for(int i=0;i<n.size();i++){
            if(n[i]==1){
                c++;
            }
            v1.push_back(n[i]);
        }
            for(int i=0;i<n.size();i++){
            
            v1.push_back(n[i]);
        }
        int c1=0;
        int i=0,j=0;
        while(i<v1.size() &&j<v1.size()){
            if(v1[j]==0){
                c1++;
            }
            while((j-i)+1>c && j<v1.size()){
                if(v1[i]==0){
                    c1--;
                }
                i++;
            }
            if((j-i)+1==c){
                min1=min(min1,c1);
            }
            j++;
        }
        return min1;

        
    }
};