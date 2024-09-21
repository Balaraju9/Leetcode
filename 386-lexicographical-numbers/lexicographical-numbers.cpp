class Solution {
public:
    vector<int> lexicalOrder(int n) {
           vector<int> v1;
     for(int i=1;i<=n;i++){
        v1.push_back(i);
     }
        sort(v1.begin(),v1.end(),[](int a,int b){
            string a1=to_string(a);
            string b1=to_string(b);
            return a1<b1;
        });
        return v1;
        
    }
};