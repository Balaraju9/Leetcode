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
        ListNode *p=h->next;
        int c=0;
        ListNode *m=h;
        while(p){
            if(p->val==0){
                m->val=c;
                m->next=p->next;
                m=m->next;
                c=0;

            }
            else{
                c+=p->val;
            }
            p=p->next;
        }
        return h;

        
    }
};