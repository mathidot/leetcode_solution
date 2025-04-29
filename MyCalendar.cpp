#include "util.h"

class MyCalendar {
private:
    std::vector<std::pair<int, int>> calendar;

    // 打印当前日历状态
    void printCalendar() const {
        std::cout << "Current Calendar: [";
        for (const auto& event : calendar) {
            std::cout << "[" << event.first << ", " << event.second << "] ";
        }
        std::cout << "]\n";
    }

public:
    MyCalendar() {
        std::cout << "Calendar initialized.\n";
    }
    
    bool book(int startTime, int endTime) {
        std::cout << "\nAttempting to book: [" << startTime << ", " << endTime << "]\n";
        
        std::pair<int, int> p;
        std::vector<std::pair<int, int>>::iterator it;
        
        // 检查是否有冲突
        for (it = calendar.begin(); it != calendar.end(); it++) {
            // 冲突条件：新事件的开始时间 < 现有事件的结束时间 且 新事件的结束时间 > 现有事件的开始时间
            if (startTime < it->second && endTime > it->first) {
                std::cout << "Conflict detected with [" << it->first << ", " << it->second << "]\n";
                printCalendar();
                return false;
            }
            
            // 找到插入位置（按开始时间排序）
            if (it->first > startTime) {
                p = *it;
                break;
            }
        }

        // 如果没有冲突，插入新事件
        if (it == calendar.end()) {
            calendar.push_back({startTime, endTime});
        } else {
            calendar.insert(it, {startTime, endTime});
        }

        std::cout << "Booking successful for [" << startTime << ", " << endTime << "]\n";
        printCalendar();
        return true;
    }
};