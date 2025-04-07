#include "util.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode *> st;
        int len = 0;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            st.push(p);
            len++;
        }
        
        ListNode *p = head;
        for (int i = 0; i < len / 2; i++) {
            ListNode *back_node = st.top();
            st.pop();
            back_node->next = p->next;
            p->next = back_node;
            p = back_node->next;
        }
        p->next = nullptr;
    }
};