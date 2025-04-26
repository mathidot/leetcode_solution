#include "util.h"

class MyCalendar {
private:
    std::vector<std::pair<int, int>> calendar;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        std::pair<int, int> p;
        std::vector<std::pair<int, int>>::iterator it;
        for (it = calendar.begin(); it != calendar.end(); it++) {
            if (it->first == startTime) return false;
            if (it->second == endTime) return false;
            if (it->first > startTime) {
                p = *it;
                break;
            }
        }
        if (it == calendar.end()) {
            calendar.push_back({startTime, endTime});
        }

        if (endTime > it->first) return false;
        calendar.insert(it, {startTime, endTime});
        return true;
    }
};
