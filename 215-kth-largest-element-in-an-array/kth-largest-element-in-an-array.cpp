class Solution {
public:
    int findKthLargest(vector<int>& n, int k) {
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i=0;i<n.size();i++){
            if(p.size()>k){
                p.pop();
            }
            p.push(n[i]);
        }
        while(p.size()>k){
            p.pop();

        }
        return p.top();
        
    }
};