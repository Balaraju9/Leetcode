class Solution {
public:
    int longestBeautifulSubstring(string w) {
        vector<pair<char,int>> v1;
        for(int i=0;i<w.size();i++){
            int i1=i;
            while(w[i]==w[i1]){
                i1++;

            }
            i1--;
            v1.push_back({w[i],i1-i+1});
            i=i1;
        }
       

        int max1=0;
        for(int i=0;i<v1.size();i++){
            if(i+4<v1.size() && v1[i].first=='a'&& v1[i+1].first=='e' && v1[i+2].first=='i' && v1[i+3].first=='o' && v1[i+4].first=='u'){
                int sum= (v1[i].second)+(v1[i+1].second)+(v1[i+2].second)+(v1[i+3].second)+(v1[i+4].second);
                max1=max(max1,sum);
              
            }
        }
        return max1;
        
    }
};