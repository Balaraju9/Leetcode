class Solution {
public:
    int maximumSwap(int num) {
        string k=to_string(num);
        vector<int> v1(k.size());
        int max1=0;
        v1[v1.size()-1]=k[v1.size()-1]-'0';
        for(int i=k.size()-2;i>=0;i--){
            max1=max(max1,v1[i+1]);
            if(max1>k[i]-'0'){
                v1[i]=max1;
            }
            else{
                max1=k[i]-'0';
                v1[i]=max1;
            }

        }
        int k4;
       for(int i=0;i<k.size();i++){
        if(k[i]-'0'!=v1[i]){
             k4=v1[i];
            for(int j=k.size()-1;j>i;j--){
                if(k4==k[j]-'0'){
                    k4=j;
                    break;
                }
            }
            swap(k[i],k[k4]);
            break;
        }
       }

       
        return stoi(k);

        
    }
};