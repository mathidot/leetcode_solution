#include "ListNode.h"

class Solution {
public:
    int getListLen(ListNode *head) {
        int ans = 0;
        while (head != nullptr) {
            ans++;
            head = head->next;
        }
        return ans;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);
        if (lenA == 0 || lenB == 0) {
            return nullptr;
        }

        if (lenA < lenB) return getIntersectionNode(headB, headA);

        int diff = lenA - lenB;
        ListNode *node = headA;
        for(int i = 0; node->next!=nullptr&&i<diff; i++, node=node->next);
        ListNode *nodeA = node;
        ListNode *nodeB = headB;
        while(nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        return nodeA;
    }
};