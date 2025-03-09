class Solution {
public:
    string mostCommonWord(string pu, vector<string>& baa) {

        
        unordered_set<string> basett(baa.begin(), baa.end());
        unordered_map<string, int> vall;

        string word;
        string result;
        int maxCount=0;

        for(int i=0; i<=pu.size(); i++){
            if(isalpha(pu[i])){ 
            word+=tolower(pu[i]);
            }else if(!word.empty()){
                if(basett.find(word)==basett.end()){
                    vall[word]++;
                }
                if(vall[word]>maxCount){
                    maxCount=vall[word];
                    result = word;
                }
                word="";
            }
        }
        return result;
    }
};