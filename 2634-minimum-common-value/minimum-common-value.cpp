class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2) {
 map<int,int> mp;
 int n22=n2.size();
    for(int i=0;i<n22;i++){
        
            mp[n2[i]]++;

        
    }
    for(int i=0;i<n1.size();i++){
        if(mp.find(n1[i])!=mp.end()){
            return n1[i];
        }
    }
    return -1;

    
   


    
   
        
    }
};