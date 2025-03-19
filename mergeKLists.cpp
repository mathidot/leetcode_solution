#include <queue>
#include "ListNode.h"
using namespace std;
struct cmp {
    bool operator()(ListNode *lhs, ListNode *rhs) {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *dummy = new ListNode(-1);
    ListNode *current = dummy;
    cmp c;
    std::priority_queue<ListNode *, std::vector<ListNode *>, cmp> minHeap;

    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != nullptr) {
            minHeap.push(lists[i]);
        }
    }
    
    while (!minHeap.empty()) {
        ListNode *top = minHeap.top();
        current->next = top;
        current = current->next;
        minHeap.pop();
        if (top->next != nullptr) {
            minHeap.push(top->next);
        }
    }

    return dummy->next;
}
};