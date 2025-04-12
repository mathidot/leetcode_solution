#include "util.h"

template <typename E>
class MonotonicQueue {
private:
    // 常规队列，存储所有元素
    std::deque<E> q;
    // 元素降序排列的单调队列，头部是最大值
    std::deque<E> maxq;
    // 元素升序排列的单调队列，头部是最小值
    std::deque<E> minq;
public:
    void push(const E& elem) {
        // 维护常规队列，直接在队尾插入元素
        q.push_back(elem);

        // 维护 maxq，将小于 elem 的元素全部删除
        while (!maxq.empty() && maxq.back() < elem) {
            maxq.pop_back();
        }
        maxq.push_back(elem);

        // 维护 minq，将大于 elem 的元素全部删除
        while (!minq.empty() && minq.back() > elem) {
            minq.pop_back();
        }
        minq.push_back(elem);
    }

    E max() const {
        // maxq 的头部是最大元素
        return maxq.front();
    }

    E min() const {
        // minq 的头部是最大元素
        return minq.front();
    }

    E pop() {
        // 从标准队列头部弹出需要删除的元素
        E deleteVal = q.front();
        q.pop_front();

        // 由于 push 的时候会删除元素，deleteVal 可能已经被删掉了
        if (deleteVal == maxq.front()) {
            maxq.pop_front();
        }
        if (deleteVal == minq.front()) {
            minq.pop_front();
        }
        return deleteVal;
    }

    int size() const {
        // 标准队列的大小即是当前队列的大小
        return q.size();
    }

    bool isEmpty() const {
        return q.empty();
    }


};