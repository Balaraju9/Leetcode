import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxCount(int m, int n, int[][] ops) {
           if(ops.length==0){
        return m*n;
       }
      int min1=99999999,min2=99999999;
       for(int i=0;i<ops.length;i++){
        min1=Math.min(min1,ops[i][0]);
        min2=Math.min(min2,ops[i][1]);
       }
    
       return min1*min2;
      
    }
}
