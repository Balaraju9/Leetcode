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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      
        vector<ListNode*> v1;
         vector<ListNode*> v4(k);

        ListNode *p=head;
        int c=0;
        while(p!=NULL){
            p=p->next;
            c++;
        }
        p=head;
        int k2=k;
        int balu1=c/k,balu2=c%k;
        int baluc1=balu1;
        int i=0;
        while(k2-- && p!=NULL){
            ListNode* pu=p;
            while(baluc1-- && p!=NULL){
                v1.push_back(p);
                p=p->next;
            }
            if(balu2>0){
                  v1.push_back(p);
                p=p->next;
                balu2--;

            }
            v4[i]=pu;
            v1[v1.size()-1]->next=NULL;
            
            baluc1=balu1;
            i++;
            

       
        }
        return v4;
        
    }
};