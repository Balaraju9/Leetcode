class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        int c=0;
        
        while(q.size()>1){
            while(c<k-1){
                q.push(q.front());
                q.pop();
                c++;

            }
            if(c==k-1){
                q.pop();
                c=0;
            }
        
        }
        return q.front();
    }
};