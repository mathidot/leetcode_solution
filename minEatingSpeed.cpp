#include "util.h"

class Solution {
public:
long finishTime(vector<int> piles, int speed) {
    long hours = 0;
    for (int i = 0; i < piles.size(); i++) {
        hours += piles[i] / speed;
        if (piles[i] % speed > 0) {
            hours++;
        }
    }
    return hours;
}

long minEatingSpeed(vector<int>& piles, int h) {
    int right = *max_element(piles.begin(), piles.end()) + 1;
    int left = 1;

    while (left < right) {
        int mid = left + ((right - left) >> 1);
        
        int t = finishTime(piles, mid);
        
        if (t > h) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
};