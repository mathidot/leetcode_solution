#include "util.h"

class FrontMiddleBackQueue {
private:
    DoubleListNode *dummy_head;
    DoubleListNode *dummy_tail;
    DoubleListNode *head;
    DoubleListNode *tail;
    DoubleListNode *middle;
    int size;

    // 打印当前队列状态
    void printQueue(const std::string& operation) {
        std::cout << "\n=== After " << operation << " ===" << std::endl;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Head: " << (head != dummy_head ? std::to_string(head->val) : "null") << std::endl;
        std::cout << "Tail: " << (tail != dummy_tail ? std::to_string(tail->val) : "null") << std::endl;
        if (middle != nullptr)
            std::cout << "Middle: " << (middle != dummy_head && middle != dummy_tail ? std::to_string(middle->val) : "null") << std::endl;
        
        std::cout << "Queue: [";
        DoubleListNode* current = dummy_head->next;
        while (current != dummy_tail) {
            if (current == head) std::cout << "\033[1;32m"; // 绿色显示head
            if (current == tail) std::cout << "\033[1;34m"; // 蓝色显示tail
            if (current == middle) std::cout << "\033[1;35m"; // 紫色显示middle
            
            std::cout << current->val;
            
            if (current == head || current == tail || current == middle) 
                std::cout << "\033[0m";
            
            current = current->next;
            if (current != dummy_tail) std::cout << " ⇄ ";
        }
        std::cout << "]" << std::endl;
    }

public:
    FrontMiddleBackQueue() : size(0) {
        dummy_head = new DoubleListNode(-1);
        dummy_tail = new DoubleListNode(-1);
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
        head = dummy_head;
        tail = dummy_tail;
        middle = nullptr;
        std::cout << "Initialized FrontMiddleBackQueue" << std::endl;
        printQueue("initialization");
    }
    
    void pushFront(int val) {
        std::cout << "\n[pushFront(" << val << ")]" << std::endl;
        DoubleListNode *node = new DoubleListNode(val);
        
        if (size == 0) {
            dummy_head->next = node;
            node->prev = dummy_head;
            node->next = dummy_tail;
            dummy_tail->prev = node;
            head = node;
            tail = node;
            middle = node;
            size++;
            printQueue("pushFront (first element)");
            return;
        }
        
        node->next = head;
        head->prev = node;
        dummy_head->next = node;
        node->prev = dummy_head;
        head = node;
        
        if (size % 2 == 1) {
            middle = middle->prev;
        }
        size++;
        
        printQueue("pushFront");
    }
    
    void pushMiddle(int val) {
        std::cout << "\n[pushMiddle(" << val << ")]" << std::endl;
        DoubleListNode *node = new DoubleListNode(val);
        
        if (size == 0) {
            dummy_head->next = node;
            node->prev = dummy_head;
            node->next = dummy_tail;
            dummy_tail->prev = node;
            head = node;
            tail = node;
            middle = node;
            size++;
            printQueue("pushMiddle (first element)");
            return;
        }

        if (size % 2 == 0) {
            // 插入到middle后面
            DoubleListNode *next_node = middle->next;
            middle->next = node;
            node->prev = middle;
            node->next = next_node;
            next_node->prev = node;
            middle = node;
        } else {
            // 插入到middle前面
            DoubleListNode *prev_node = middle->prev;
            node->next = middle;
            middle->prev = node;
            prev_node->next = node;
            node->prev = prev_node;
            middle = node;
            if (size == 1) {
                head = middle;
            }
        }
        size++;
        
        printQueue("pushMiddle");
    }
    
    void pushBack(int val) {
        std::cout << "\n[pushBack(" << val << ")]" << std::endl;
        DoubleListNode *node = new DoubleListNode(val);
        
        if (size == 0) {
            dummy_head->next = node;
            node->prev = dummy_head;
            node->next = dummy_tail;
            dummy_tail->prev = node;
            head = node;
            tail = node;
            middle = node;
            size++;
            printQueue("pushBack (first element)");
            return;
        }

        tail->next = node;
        node->prev = tail;
        node->next = dummy_tail;
        dummy_tail->prev = node;
        tail = node;
        
        if (size % 2 == 0) {
            middle = middle->next;
        }
        size++;
        
        printQueue("pushBack");
    }
    
    int popFront() {
        std::cout << "\n[popFront()]" << std::endl;
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            printQueue("popFront (empty)");
            return -1;
        }
        
        int headVal = head->val;
        if (size == 1) {
            dummy_head->next = dummy_tail;
            dummy_tail->prev = dummy_head;
            delete head;
            head = dummy_head;
            middle = nullptr;
            tail = dummy_tail;
            size--;
            printQueue("popFront (last element)");
            return headVal;
        }
        
        if (size % 2 == 0) {
            middle = middle->next;
        }
        
        dummy_head->next = head->next;
        head->next->prev = dummy_head;
        delete head;
        head = dummy_head->next;
        size--;
        
        printQueue("popFront");
        return headVal;
    }
    
    int popMiddle() {
        std::cout << "\n[popMiddle()]" << std::endl;
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            printQueue("popMiddle (empty)");
            return -1;
        }
        
        int middle_val = middle->val;
        if (size == 1) {
            dummy_head->next = dummy_tail;
            dummy_tail->prev = dummy_head;
            delete middle;
            head = dummy_head;
            tail = dummy_tail;
            middle = nullptr;
            size--;
            printQueue("popMiddle (last element)");
            return middle_val;
        }

        if (size == 2) {
            middle->next->prev = middle->prev;
            middle->prev->next = middle->next;
            delete middle;
            middle = dummy_head->next;
            head = middle;
            tail = middle;
            size--;
            printQueue("popMiddle (size=2)");
            return middle_val;
        }

        DoubleListNode* new_middle;
        if (size % 2 == 0) {
            new_middle = middle->next;
        } else {
            new_middle = middle->prev;
        }
        
        middle->next->prev = middle->prev;
        middle->prev->next = middle->next;
        delete middle;
        middle = new_middle;
        size--;
        
        printQueue("popMiddle");
        return middle_val;
    }
    
    int popBack() {
        std::cout << "\n[popBack()]" << std::endl;
        if (size == 0) {
            std::cout << "Queue is empty!" << std::endl;
            printQueue("popBack (empty)");
            return -1;
        }
        
        int backVal = tail->val;
        if (size == 1) {
            dummy_head->next = dummy_tail;
            dummy_tail->prev = dummy_head;
            delete tail;
            head = dummy_head;
            middle = nullptr;
            tail = dummy_tail;
            size--;
            printQueue("popBack (last element)");
            return backVal;
        }
        
        if (size % 2 == 1) {
            middle = middle->prev;
        }
        
        tail->prev->next = dummy_tail;
        dummy_tail->prev = tail->prev;
        delete tail;
        tail = dummy_tail->prev;
        size--;
        
        printQueue("popBack");
        return backVal;
    }
};

class FrontMiddleBackQueue {
    // 用两个列表表示队列的左右两部分，一遍从中间操作元素
    deque<int> left;
    deque<int> right;
    // 如果是奇数个元素，维护左边少右边多，所以：
    // 1、如果有偶数个元素时，pushMiddle 优先向右边添加
    // 2、如果有奇数个元素时，popMiddle 优先从右边删除
    // 3、如果只有 1 个元素，popFront 的时候，要去右边删除
    // 要把以上三个特点写到代码里，才能保证细节不出错

    // 维护左边少右边多的状态，每次增删元素之后都要执行一次
    void balance() {
        // 右边最多比左边多一个元素
        if (right.size() > left.size() + 1) {
            // 右边多，匀一个给左边
            left.push_back(right.front());
            right.pop_front();
        }
        if (left.size() > right.size()) {
            // 左边多，匀一个给右边
            right.push_front(left.back());
            left.pop_back();
        }
    }

public:
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (size() % 2 == 0) {
            // 如果有偶数个元素时，pushMiddle 优先向右边添加
            right.push_front(val);
        } else {
            left.push_back(val);
        }
        balance();
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (size() == 0) {
            return -1;
        }
        if (size() == 1) {
            // 如果只有 1 个元素，popFront 的时候，要去右边删除
            int e = right.front();
            right.pop_front();
            return e;
        }
        int e = left.front();
        left.pop_front();
        balance();
        return e;
    }

    int popMiddle() {
        if (size() == 0) {
            return -1;
        }
        int e;
        if (size() % 2 == 0) {
            e = left.back();
            left.pop_back();
        } else {
            // 如果有奇数个元素时，popMiddle 优先从右边删除
            e = right.front();
            right.pop_front();
        }
        balance();
        return e;
    }

    int popBack() {
        if (size() == 0) {
            return -1;
        }
        int e = right.back();
        right.pop_back();
        balance();
        return e;
    }

    int size() {
        return left.size() + right.size();
    }
};

// 测试用例
int main() {
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);
    q.popFront();
    q.popMiddle();
    q.popMiddle();
    q.popBack();
    q.popFront();
    return 0;
}