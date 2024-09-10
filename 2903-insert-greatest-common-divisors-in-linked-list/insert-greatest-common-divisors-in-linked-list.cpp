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
    ListNode* insertGreatestCommonDivisors(ListNode* h) {
        ListNode* p=h;
        vector<int> v1;
        while(p!=NULL){
            v1.push_back(p->val);
            p=p->next;
        }
        if(v1.size()==1){
            return h;
        }
        vector<int> v2;
        for(int i=1;i<v1.size();i++){
            v2.push_back(__gcd(v1[i],v1[i-1]));
        }
        p=h;
        int i=0;
        while(p!=NULL){
            ListNode* t=p->next;
            p->next=new ListNode(v2[i]);
            
            p=p->next;
            p->next=t;
            i++;
            p=p->next;
            if(i>=v2.size()){
                break;
            }
        }
        return h;

        
    }
};