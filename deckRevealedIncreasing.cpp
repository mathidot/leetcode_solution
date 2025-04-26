#include "util.h"

/*
[17,13,11,2,3,5,7]
[2,3,5,7]
[13,11,17]
[2,13,3,11,5,17,7]
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        size_t n = deck.size();
        std::deque<int> res;
        std::sort(deck.begin(), deck.end(), std::greater<int>());
        for (int i = 0; i < deck.size(); i++) {
            if (!res.empty()) {
                res.push_front(res.back());
                res.pop_back();
            }
            res.push_front(deck[i]);
        }
    }
};

// pop_front -> (pop_front() ->push_back)
// push_front -> (pop_back -> push_front)