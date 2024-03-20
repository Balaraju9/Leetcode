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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        ListNode *t1=l1,*t2=l1;
        int a1=a,b1=b;
        a1--;
        while(a1--){
            t1=t1->next;

        }
       b1++;
        while(b1--){
            t2=t2->next;
        }


        t1->next=l2;
        while(t1->next!=NULL){
            t1=t1->next;
        }
        t1->next=t2;
        return l1;
        
    }
};