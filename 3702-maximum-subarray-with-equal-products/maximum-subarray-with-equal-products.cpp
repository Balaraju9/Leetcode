class Solution {
public:
    int maxLength(vector<int>& n) {
        long long int max1=0,lcm1=0,gcd1=0,s=1;
        for(int i=0;i<n.size();i++){
            lcm1=n[i],gcd1=n[i];
            s=1;
            for(int j=i;j<n.size();j++){
                s=(long long)s*(long long)n[j];
                if(s>INT_MAX) break;
              
                lcm1=lcm(n[j],lcm1);
                gcd1=__gcd((int)n[j],(int)gcd1);
                if(s==(lcm1*gcd1)){
                    max1=max((int)max1,(j-i)+1);
                }

            }

            
        }
        return max1;
        
    }
};