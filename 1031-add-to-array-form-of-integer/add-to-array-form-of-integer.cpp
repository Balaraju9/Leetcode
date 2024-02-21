class Solution {
public:
    vector<int> addToArrayForm(vector<int>& n, int k) {
        int i=n.size()-1;
        string s=to_string(k);
        int j=s.size()-1;
        int c=0;
        vector<int> v1;
        while(i!=-1 && j!=-1){
            int su=c+n[i]+(s[j]-48);
            if(su<=9){
                v1.push_back(su);
                c=0;
                i--;
                j--;
            }
            else{
                v1.push_back(su%10);
                c=su/10;
                i--;
                j--;
            }

        }
          while(i!=-1 ){
            int su=c+n[i];
            if(su<=9){
                v1.push_back(su);
                c=0;
                i--;
                
            }
            else{
                v1.push_back(su%10);
                c=su/10;
                i--;
                
            }

        }
            while(j!=-1){
            int su=c+(s[j]-48);
            if(su<=9){
                v1.push_back(su);
                c=0;
               
                j--;
            }
            else{
                v1.push_back(su%10);
                c=su/10;
                
                j--;
            }

        }
        if(c){
            v1.push_back(c);
        } 
        reverse(v1.begin(),v1.end());
        return v1;       
    }
};