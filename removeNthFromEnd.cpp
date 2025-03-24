#include "ListNode.h"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        for (int i = 0; fast->next != nullptr && i < n-1; i++) {
            fast  = fast->next;
        }

        if (fast == nullptr) return nullptr;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        while(fast->next != nullptr) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev == nullptr) {
            if (head != nullptr) {
                ListNode *ans = head->next;
                head->next = nullptr;
                delete(head);
                return ans;
            }
            return nullptr;
        }

        prev->next = slow->next;
        slow->next = nullptr;
        delete(slow);

        return head;
    }
};