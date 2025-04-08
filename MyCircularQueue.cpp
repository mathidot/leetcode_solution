#include "util.h"

class MyCircularQueue {
private:
    std::vector<int> array;
    int capacity = 0;
    int start = 0;
    int end = 0;
    // 打印当前队列状态
    void printQueue(const std::string& operation) {
        std::cout << "\n=== After " << operation << " ===" << std::endl;
        std::cout << "Start: " << start << ", End: " << end << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
        
        std::cout << "Queue: [";
        for (int i = 0; i < capacity; ++i) {
            if (i == start % capacity && i == (end - 1) % capacity && !isEmpty()) {
                std::cout << "\033[1;31m" << array[i] << "\033[0m"; // 红色显示唯一元素
            }
            else if (i == start % capacity && !isEmpty()) {
                std::cout << "\033[1;32m" << array[i] << "\033[0m"; // 绿色显示队首
            }
            else if (i == (end - 1) % capacity && !isEmpty()) {
                std::cout << "\033[1;34m" << array[i] << "\033[0m"; // 蓝色显示队尾
            }
            else if ((start % capacity <= i && i < end % capacity) || 
                    (end % capacity < start % capacity && (i >= start % capacity || i < end % capacity))) {
                std::cout << array[i];
            }
            else {
                std::cout << "-"; // 空位置
            }
            
            if (i != capacity - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
        
        std::cout << "Status: ";
        if (isEmpty()) std::cout << "Empty";
        if (isFull()) std::cout << "Full";
        if (!isEmpty() && !isFull()) std::cout << "Normal";
        std::cout << std::endl;
    }
public:
    MyCircularQueue(int k) {
        array.resize(k+1, 0);
        capacity = k+1;
    }
    
    bool enQueue(int value) {
        std::cout << "\nAttempting to enQueue: " << value << std::endl;
        if (!isFull()) {
            array[end % capacity] = value;
            end += 1;
            printQueue("enQueue " + std::to_string(value));
            return true;
        } else {
            std::cout << "Failed - Queue is full!" << std::endl;
            printQueue("failed enQueue");
            return false;
        }
    }
    
    bool deQueue() {
        std::cout << "\nAttempting to deQueue" << std::endl;
        if (!isEmpty()) {
            int val = array[start % capacity];
            start += 1;
            std::cout << "Dequeued value: " << val << std::endl;
            printQueue("deQueue");
            return true;
        } else {
            std::cout << "Failed - Queue is empty!" << std::endl;
            printQueue("failed deQueue");
            return false;
        }
    }
    
    int Front() {
        int val = (!isEmpty()) ? array[start % capacity] : -1;
        std::cout << "\nFront: " << val << std::endl;
        printQueue("Front check");
        return val;
    }
    
    int Rear() {
        int val = (!isEmpty()) ? array[(end - 1) % capacity] : -1;
        std::cout << "\nRear: " << val << std::endl;
        printQueue("Rear check");
        return val;
    }
    
    bool isEmpty() {
        return start == end;
    }
    
    bool isFull() {
        return (end + 1) % capacity == start;      
    }
};

// 测试用例
int main() {
    MyCircularQueue cq(3);
    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    cq.enQueue(4); // 这个会失败
    cq.deQueue();
    cq.enQueue(4);
    cq.Front();
    cq.Rear();
    cq.deQueue();
    cq.deQueue();
    cq.deQueue(); // 这个会失败
    return 0;
}