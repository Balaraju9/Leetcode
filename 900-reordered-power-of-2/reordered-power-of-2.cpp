class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s1=to_string(n);
        
        long long int len=0;
        long long int pow1=pow(2,len);
        string s2=to_string(pow1);
       while(s2.size()!=s1.size()){
        len++;
        pow1=pow(2,len);
        s2=to_string(pow1);

       }
       vector<string> v1;
       while(s2.size()==s1.size()){
        v1.push_back(s2);
         len++;
        pow1=pow(2,len);
        s2=to_string(pow1);



       }
       sort(s1.begin(),s1.end());
     for(auto &i:v1){
        sort(i.begin(),i.end());
        if(i==s1) return true;
        
     }
       return 0;

        
    }
};