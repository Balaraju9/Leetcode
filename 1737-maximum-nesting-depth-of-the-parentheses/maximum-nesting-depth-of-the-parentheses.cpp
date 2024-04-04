class Solution {
public:
    int maxDepth(string s) {
        int k=0,max1=0,c=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='('){
            c++;
            max1=max(max1,c);
            
           }
           else if(s[i]==')'){
            c--;
           }
        }
        return max1;
        
    }
};