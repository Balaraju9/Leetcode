class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        for(int i=0;i<h.size();i++){
            for(int j=0;j<h.size();j++){
                if(h[i]>h[j]){
                    swap(h[i],h[j]);
                    swap(n[i],n[j]);
                }

            }
        }
        return n;
        
    }
};