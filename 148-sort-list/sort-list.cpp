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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dumm = new ListNode(-1);
        ListNode* t = dumm;
        while (left != NULL && right != NULL) {
            if (left->val > right->val) {
                dumm->next = right;
                right = right->next;

            } else {
                dumm->next = left;
                left = left->next;
            }
            dumm = dumm->next;
        }
        while (left != NULL) {

            dumm->next = left;
            left = left->next;

            dumm = dumm->next;
        }
        while (right != NULL) {

            dumm->next = right;
            right = right->next;

            dumm = dumm->next;
        }
        return t->next;
    }
    ListNode* fun(ListNode* pu) {
        ListNode* sl = pu;
        ListNode* fa = pu->next;
        while (fa != NULL && fa->next != NULL) {
            sl = sl->next;
            fa = fa->next->next;
        }
        return sl;
    }
    ListNode* divide(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* middle = fun(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        left = divide(left);
        right = divide(right);
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) { return divide(head); }
};