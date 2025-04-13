#include "util.h"

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        const int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top();
            s.push(nums[i]);
        }
        return ans;
    }
};