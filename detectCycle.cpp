#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *node = head;
                while(node != fast) {
                    node = node->next;
                    fast = fast->next;
                }
                return node;
            }
        }        
        return nullptr;
    }
};