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
    ListNode* modifiedList(vector<int>& n, ListNode* h) {
        ListNode *p=h;
        unordered_map<int,int> mp;
        for(auto &i:n){
            mp[i]++;
        }
        while(p!=NULL && mp.find(p->val)!=mp.end()){
            p=p->next;
        }
        
        if(p==NULL){
            return NULL;
        }
        h=p;
        while(p!=NULL && p->next!=NULL){
            if(p!=NULL && p->next!=NULL && mp.find(p->next->val)!=mp.end()){
                p->next=p->next->next;
            }
            else if(p!=NULL && p->next!=NULL){
                p=p->next;
            }
        }
        return h;

      
        
    }
};