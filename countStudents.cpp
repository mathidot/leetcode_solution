#include "util.h"

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::deque<int> studuents_q(students.begin(), students.end());
        std::deque<int> sandwiches_q(sandwiches.begin(), sandwiches.end());
        int consecutive_failures = 0;
        while (!sandwiches_q.empty()) {
            if (studuents_q.front() == sandwiches_q.front()) {
                studuents_q.pop_front();
                sandwiches_q.pop_front();
                consecutive_failures = 0;
            } else {
                studuents_q.push_back(studuents_q.front());
                studuents_q.pop_front();
                consecutive_failures++;
                if (consecutive_failures == studuents_q.size()) {
                    return studuents_q.size();
                }
            }
        }
        return 0;
    }
};