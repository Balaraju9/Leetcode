class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& ar, int k) {
        map<int,int> mp;
        for(auto &i:ar){
            mp[i]++;
        }
        vector<int> v1;
        for(auto &i:mp){
            v1.push_back(i.second);
        }
       
        sort(v1.begin(),v1.end());
        int l=0,s=0;
       for(int i=0;i<v1.size();i++){
           s=s+v1[i];

           if(s>=k){
               l=i;
               

               break;
           }

            
          
       }
       
       if(s==k){
            return (v1.size()-1)-l;

       }
      return  (v1.size()-1)-l+1;

       

        
    }
};