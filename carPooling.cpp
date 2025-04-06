#include "util.h"
#include "Difference.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1000+1);
        Difference diff(nums);

        for (const auto& trip: trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            diff.increment(from, to-1, numPassengers);
        }
        auto res = diff.result();
        for (int i = 0; i < res.size(); i++) {
            if (res[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};