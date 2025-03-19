#include "ListNode.h"
class Solution {
public:
    ListNode* moveToHead(ListNode **head, ListNode **prev, ListNode *curr) {
        if (curr == *head) {
            *prev = *head;
            return (*head)->next;
        }
        (*prev)->next = curr->next;
        curr->next = *head;
        *head = curr;
        return (*prev)->next;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode *markNode = nullptr;
        if (head == nullptr) return nullptr;
        ListNode *prev = nullptr, *curr = head;
        while(curr != nullptr) {
            if (curr->val < x) {
                if (markNode == nullptr) {
                    curr = moveToHead(&head, &prev, curr);
                    markNode = head;
                } else {
                    if (markNode == prev) {
                        markNode = curr;
                        prev = curr;
                        curr = curr->next;
                    } else {
                        prev->next = curr->next;
                        ListNode *temp = curr->next;
                        curr->next = markNode->next;
                        markNode->next = curr;
                        curr = temp;
                        markNode = markNode->next;
                    }
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};