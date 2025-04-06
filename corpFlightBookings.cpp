#include "util.h"
#include "Difference.h"

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n, 0);
        Difference diff(nums);
        for (const auto &book: bookings) {
            int first = book[0]-1;
            int last = book[1]-1;
            int seats = book[2];
            diff.increment(first, last, seats);
        }
        auto res = diff.result();
        return res;
    }
};