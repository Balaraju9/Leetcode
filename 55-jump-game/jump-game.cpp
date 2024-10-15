class Solution {
public:
    bool canJump(vector<int>& n) {
    vector<bool> v1(n.size());
    v1[n.size()-1]=true;
    for(int i=n.size()-2;i>=0;i--){
        if(n[i]==0){
            v1[i]=false;
        }
        else{
      for(int j=i;j<=i+n[i];j++){
        if(v1[j]==1){
            v1[i]=1;
            break;
        }
      }
        }
    


    }
    return v1[0];

        
    }
};