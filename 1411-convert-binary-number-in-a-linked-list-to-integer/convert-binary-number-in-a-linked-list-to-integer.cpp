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
    int getDecimalValue(ListNode* h) {
        int c=0;
        ListNode* pu=h;
        while(pu!=NULL){
            pu=pu->next;
            c++;
        }
        pu=h;
        int ans=0;
        while(pu!=NULL){
            if(pu->val==1){
                ans+=pow(2,c-1);
            }
            c--;
            pu=pu->next;

        }

return ans;
        
    }
};