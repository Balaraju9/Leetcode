class Solution {
public:
    int minimumRecolors(string b, int k) {
        vector<int> v1(b.size());
        int c1=0;
        for(int i=0;i<b.size();i++){
            if(b[i]=='W'){
                c1++;
            }
            v1[i]=c1;
        }
        int min1=v1[k-1];
        int j1=k;
        int ind=0;
        while(j1<b.size()){
            min1=min(min1,(v1[j1]-v1[ind]));
            j1++;
            ind++;


        }
        return min1;
    }
};