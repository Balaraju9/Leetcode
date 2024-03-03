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
    ListNode* removeNthFromEnd(ListNode* h, int n) {
        ListNode *t=h;
           int c1=0,c=0;
        while(t!=NULL){
            t=t->next;
            c++;
        }
        t=h;
     
        while(t!=NULL){
            c1++;
            if((c-c1)==n){
                break;
            }
            t=t->next;
            
        }
        if(t!=NULL){
            t->next=t->next->next;
        }
        else{
            return h->next;
        }
       
        return h;
        
    }
};