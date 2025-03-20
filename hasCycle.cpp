#include "ListNode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        if (fast == slow) return true;
        while (slow != nullptr && fast != nullptr) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) return false;
            fast = fast->next;
        }
        return false;
    }
};