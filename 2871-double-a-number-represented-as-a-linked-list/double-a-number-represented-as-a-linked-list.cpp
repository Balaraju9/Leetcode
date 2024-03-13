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
    ListNode* doubleIt(ListNode* h) {
        ListNode *t=h,*temp=NULL,*prev=NULL;

        while(t!=NULL){
            temp=t->next;
            t->next=prev;
            prev=t;
            t=temp;


        }
        t=prev;
        int c=0,k=0,k1=0;
        while(t!=NULL){
            k=2*t->val+c;
            if(k>9){
                k1=k%10;
                c=k/10;
                t->val=k1;
                t=t->next;

            }
            else{
                c=0;
                t->val=k;
                t=t->next;

            }
            

            

        }
        if(c!=0){
           t=prev;
           while(t->next!=NULL){
            t=t->next;

           }
           t->next=new ListNode(c);
        }
        h=prev;
        prev=NULL;
        temp=NULL;
        t=h;
        while(t!=NULL){
            temp=t->next;
            t->next=prev;
            prev=t;
            t=temp;
        }
        return prev;
        
        
        
    }
};