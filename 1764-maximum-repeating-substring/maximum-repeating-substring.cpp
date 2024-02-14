class Solution {
public:
    int maxRepeating(string s, string w) {
        string s1="";
        int max1=0;
        while(s1.size()<s.size()){
            s1=s1+w;

            if(s.find(s1)!=string::npos){
                int z=s1.size()/w.size();
                max1=max(max1,z);
            }
            

        }
        return max1;
        
    }
};