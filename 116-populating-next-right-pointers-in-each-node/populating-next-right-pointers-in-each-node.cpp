/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* pu;
    Node* connect(Node* root) {
        pu=root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> q1=q;
            while(!q.empty()){
                q.pop();
            }
            

            while(!q1.empty()){
                Node* balu=q1.front();
                q1.pop();
                if(balu && balu->left){
                    q.push(balu->left);
                }
                if(balu && balu->right){
                    q.push(balu->right);
                }
                if(balu && q1.empty()){
                    balu->next=NULL;
                }
                else{
                    if(balu){
                    balu->next=q1.front();
                }
                }
                

            }
          
        }
        return root;
        
    }
};