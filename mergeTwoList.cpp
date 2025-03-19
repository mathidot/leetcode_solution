#include "ListNode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *newHead = new ListNode(0);
        ListNode *cur = newHead;

        ListNode *head1 = list1, *head2 = list2;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            } else {
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }

        if (head1 == nullptr) {
            while (head2 != nullptr) {
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }

        if (head2 == nullptr) {
            while (head1 != nullptr) {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            }
        }

        return newHead->next;
    }
};
