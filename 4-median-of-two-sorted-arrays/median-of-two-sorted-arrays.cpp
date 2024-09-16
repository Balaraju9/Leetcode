class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        int k1=n1.size(),k2=n2.size();
        int m1,m2,c,c1;
        if((k1+k2)%2==0){
             m1=(k1+k2)/2;
             m2=m1-1;
             c=0,c1=0;
            int c3=0;
            int i=0,j=0;
            while(i<n1.size() && j<n2.size()){
                if(n1[i]<n2[j]){
                    if(c3==m1){
                        c=n1[i];
                    }
                    if(c3==m2){
                        c1=n1[i];
                    }
                    i++;
                         
                }
                else{
                           if(c3==m1){
                        c=n2[j];
                    }
                    if(c3==m2){
                        c1=n2[j];
                    }
                    j++;
                          
                }
                c3++;
                
            }
              while(i<n1.size() ){
               
                    if(c3==m1){
                        c=n1[i];
                    }
                    if(c3==m2){
                        c1=n1[i];
                    }
                    i++;
                         
                
           
                c3++;
                
            }
                  while(j<n2.size() ){
               
                    if(c3==m1){
                        c=n2[j];
                    }
                    if(c3==m2){
                        c1=n2[j];
                    }
                    j++;
                         
                
           
                c3++;
                
            }
              
        return (c+c1)/2.0;

        }
        else{
               m1=(k1+k2)/2;
            
             c=0;
            int c3=0;
            int i=0,j=0;
            while(i<n1.size() && j<n2.size()){
                if(n1[i]<n2[j]){
                    if(c3==m1){
                        c=n1[i];
                    }
                 
                    i++;
                         
                }
                else{
                           if(c3==m1){
                        c=n2[j];
                    }
                 
                    j++;
                          
                }
                c3++;
                
            }
              while(i<n1.size() ){
               
                    if(c3==m1){
                        c=n1[i];
                    }
                  
                    i++;
                         
                
           
                c3++;
                
            }
                  while(j<n2.size() ){
               
                    if(c3==m1){
                        c=n2[j];
                    }
                  
                    j++;
                         
                
           
                c3++;
                
            }
            cout<<c;
            return c/1.0;

        }
      
        return 0;
        
    }
};