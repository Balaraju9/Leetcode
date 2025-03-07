class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        vector<int> v1(s.size());
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                c++;
            }
            v1[i]=c;
        }
        vector<int> v2;
        vector<int> h1(s.size());
         vector<int> h2(s.size());
         int h11=-1;
         int h22=-1;
        for(int i=h1.size()-1;i>=0;i--){
            if(s[i]=='|'){
                h11=i;
            }
            h1[i]=h11;

        }
        for(int i=0;i<h2.size();i++){
             if(s[i]=='|'){
                h22=i;
            }
            h2[i]=h22;

        }
        
       
        for(int i=0;i<q.size();i++){
            int pu1=q[i][1];
            int pu2=q[i][0];
            pu1=h2[pu1];
            pu2=h1[pu2];
           
            if(pu1<=pu2 || pu1==-1 || pu2==-1){
            v2.push_back(0);
            }
            else{
 v2.push_back(v1[pu1]-v1[pu2]);
            

            }

        }
        return v2;
        
    }
};