/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* h) {
        ListNode *p=h;
        ListNode *n=new ListNode(0);
        ListNode *n1=n;
        int c=0;
        while(p){
            if(p->val==0){
                n1->next=new ListNode(c);
                n1=n1->next;
                c=0;

            }
            else{
                c=c+p->val;
            }
            p=p->next;
        }
        while(n->val==0){
            n=n->next;
        }
        
        return n;
        
    }
};