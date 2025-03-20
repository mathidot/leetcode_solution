#include "ListNode.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head, *fast = head;
        while(1) {
            if (fast->next == nullptr) {
                return slow;
            }
            if (fast->next->next == nullptr) {
                return slow->next;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};