class Solution {
public:
    vector<string> removeAnagrams(vector<string>& w) {
        vector<string> w1=w;
        for(int i=0;i<w.size();i++){
            sort(w[i].begin(),w[i].end());
        }
        int i=0;
        vector<string> v1;
        while(i<w.size()){
            string pu=w[i];
            v1.push_back(w1[i]);
            if(pu==w[i]){
            while(pu==w[i]  && i<w.size()){
                i++;
                if(i==w.size()){
                    break;
                }
                
            }
        }
        

        
    }
    return v1;
    }
};