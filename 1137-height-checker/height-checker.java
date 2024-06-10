import java.util.Vector;
import java.util.Collections;
class Solution {
    public int heightChecker(int[] h) {
       int[] v=h.clone();
       Arrays.sort(v);
       
        
        int pu=0;
        for(int i=0;i<h.length;i++){
            if(h[i]!=v[i]){
                pu++;
            }
        }
        return pu;
        
    }
}