#include "util.h"

class RecentCounter {
public:
    queue<int> q;

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            // t 是递增的，所以可以从队头删除 3000 毫秒之前的请求
            q.pop();
        }

        return q.size();
    }
};
// 测试用例
int main() {
    RecentCounter rc;
    rc.ping(1);
    rc.ping(100);
    rc.ping(3001);
    rc.ping(3002);
    return 0;
}