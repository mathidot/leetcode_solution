#include "util.h"

class Solution {
public:
    int calcTime(vector<int> &weights, int power) {
        int time = 0;
        int p = power;
        for (int i = 0; i < weights.size(); i++) {
            if (p - weights[i] < 0) {
                p = power;
                time += 1;
                p -= weights[i];
            } else {
                p -= weights[i];
            }
        }
        return time+1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0) + 1;
        while (left < right) {
            int mid = left + (right - left) >> 1;
            int t = calcTime(weights, mid);
            if (t > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};