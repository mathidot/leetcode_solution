#include "util.h"

class MyStack {
    queue<int> q;
    int top_elem = 0;

public:
    /**
     * 添加元素到栈顶
     */
    void push(int x) {
        // x 是队列的队尾，是栈的栈顶
        q.push(x);
        top_elem = x;
    }

    /**
     * 返回栈顶元素
     */
    int top() {
        return top_elem;
    }

    /**
     * 删除栈顶的元素并返回
     */
    int pop() {
        int size = q.size();
        // 留下队尾 2 个元素
        while (size > 2) {
            q.push(q.front());
            q.pop();
            size--;
        }
        // 记录新的队尾元素
        top_elem = q.front();
        q.push(q.front());
        q.pop();
        // 删除之前的队尾元素
        int tmp=q.front();
        q.pop();
        return tmp;
    }

    /**
     * 判断栈是否为空
     */
    bool empty() {
        return q.empty();
    }
};