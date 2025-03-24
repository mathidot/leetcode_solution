#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode* deleteDuplicates_old(ListNode* head) {
        ListNode *dummyDup = new ListNode(101);
        ListNode *dummyUniq = new ListNode(101);

        ListNode *curDup = dummyDup;
        ListNode *curUniq = dummyUniq;

        ListNode *cur = head;
        while(cur != nullptr) {
            if ((cur->next != nullptr && cur->val == cur->next->val) || cur->val == curDup->val) {
                curDup->next = cur;
                curDup = curDup->next;
            } else {
                curUniq->next = cur;
                curUniq = curUniq->next;
            }
            cur = cur->next;
            curDup->next = nullptr;
            curUniq->next = nullptr;
        }
        return dummyUniq->next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(101);
        ListNode *slow = dummy;
        ListNode *fast = head;

        while (fast != nullptr) {
            if (fast->next != nullptr && fast->val == fast->next->val) {
                while (fast->next != nullptr && fast->val == fast->next->val) {
                    fast = fast->next;
                }
                fast = fast->next;
                if (fast == nullptr) {
                    slow->next = nullptr;
                }
            } else {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            } 
        }

        return dummy->next;
    }

    ListNode* deleteDuplicates_recursive(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head == nullptr || head->next == nullptr) return head;
        if (head->val != head->next->val) {
            head->next = deleteDuplicates_recursive(head->next);
            return head;
        }

        while (head->next != nullptr && head->val == head->next->val) {
            head = head->next;
        }
        return deleteDuplicates_recursive(head->next);
    }

};