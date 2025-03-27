#include "util.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        int h = 0, l = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (p1 != nullptr && p2 != nullptr) {
            l = (p1->val + p2->val + h) % 10;
            h = (p1->val + p2->val + h) / 10;
            ListNode *node = new ListNode(l);
            cur->next = node;
            cur = cur->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1 != nullptr) { 
            l = (p1->val + h) % 10;
            h = (p1->val + h) / 10;
            ListNode *node = new ListNode(l);
            cur->next = node;
            cur = cur->next;
            p1 = p1->next; 
        }
        while (p2 != nullptr) { 
            l = (p2->val + h) % 10;
            h = (p2->val + h) / 10;
            ListNode *node = new ListNode(l);
            cur->next = node;
            cur = cur->next;
            p2 = p2->next; 
        }

        if (h != 0) {
            ListNode *node = new ListNode(h);
            cur->next = node;
            cur = cur->next;
        }

        return dummy->next;
    }
};