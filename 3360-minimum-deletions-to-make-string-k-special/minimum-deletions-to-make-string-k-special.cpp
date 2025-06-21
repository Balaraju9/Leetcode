class Solution {
public:
    int fun(int i,int j,int k,vector<int> &freq,vector<vector<int>> &v1){

        if(i==j) return 0;
        if(freq[j]-freq[i]<=k) return 0;
        if(v1[i][j]!=-1) return v1[i][j];
        return v1[i][j]=min(freq[i]+fun(i+1,j,k,freq,v1),(freq[j]-(freq[i]+k))+fun(i,j-1,k,freq,v1));//maya endukanta manaki telidu ekkada return chesthundo like ekkadunundo chesi anni vaakadaagran condition statisfly avthundhi ok appudu inka emi undavu so ad return chesthundhi
        
    }
    int minimumDeletions(string w, int k) {
        vector<vector<int>> v1(26,vector<int>(26,-1));
        vector<int> freq;
        unordered_map<char,int> mp;
        for(int i=0;i<w.size();i++){
            mp[w[i]]++;
           

        }
        for(auto &i:mp){
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        return fun(0,freq.size()-1,k,freq,v1);
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1[i].size();j++){
                cout<<v1[i][j]<<" ";
            }
            cout<<"\n";
        }
        return 3;
        
        
    }
};