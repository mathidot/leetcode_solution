#include "util.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<ListNode *> st1;
        std::stack<ListNode *> st2;
        ListNode *cur1 = l1, *cur2 = l2;                
        while (cur1 != nullptr) {
            st1.push(cur1);
            cur1 = cur1->next;
        }
        while (cur2 != nullptr) {
            st2.push(cur2);
            cur2 = cur2->next;
        }

        int l = 0, h = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = nullptr;
        while(!st1.empty() && !st2.empty()) {
            auto node1 = st1.top();
            auto node2 = st2.top();
            st1.pop();
            st2.pop();
            l = (node1->val + node2->val + h) % 10;
            h = (node1->val + node2->val + h) / 10;
            ListNode *node = new ListNode(l);                                    
            dummy->next = node;
            node->next = cur;
            cur = node;
        }

        while (!st1.empty()) { 
            auto node1 = st1.top();
            st1.pop();
            l = (node1->val + h) % 10;
            h = (node1->val + h) / 10;
            ListNode *node = new ListNode(l);
            dummy->next = node;
            node->next = cur;
            cur = node;
        }
        while (!st2.empty()) { 
            auto node2 = st2.top();
            st2.pop();
            l = (node2->val + h) % 10;
            h = (node2->val + h) / 10;
            ListNode *node = new ListNode(l);
            dummy->next = node;
            node->next = cur;
            cur = node;
        }

        if (h != 0) {
            ListNode *node = new ListNode(h);
            dummy->next = node;
            node->next = cur;
            cur = node;
        }
        return dummy->next;
    }
};