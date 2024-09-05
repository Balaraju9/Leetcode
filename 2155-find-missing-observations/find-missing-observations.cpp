class Solution {
public:
    vector<int> missingRolls(vector<int>& r, int mean, int n) {
        int s=0;
        for(int i=0;i<r.size();i++){
            s+=r[i];
        }
        if((6*n < ((r.size()+n)*mean )-s)){
            return {};
        }
        if(s>(r.size()+n)*mean ){
            return {};
        }
        vector<int> v1(n);
        int bal=((r.size()+n)*mean )-s;
        for(int i=0;i<v1.size();i++){
            if(bal>=6){
                v1[i]=6;
                bal=bal-6;
            }
            else if(bal!=0 && bal<6){
                v1[i]=bal;
                break;
            }
        }
        sort(v1.begin(),v1.end());
        int i=0,j=v1.size()-1;
        while( i<v1.size() && j<v1.size() && i<=j){
            while(v1[j]>1 && v1[i]==0 && i<v1.size() && j<v1.size()){
                v1[i]=1;
                v1[j]--;
                i++;
            }
             if(v1[j]==1){
                j--;

            }
            else {
              break;
            }
          

        }
        for(auto &i:v1){
            if(i==0){
                return {};
            }
        }
        return v1;

        
    }
};