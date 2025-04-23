#include "util.h"

class LRUCache {
private:
    int capacity = 0;
    // key -> value
    std::unordered_map<int, int> cache;
    std::list<int> lru_queue;
    std::unordered_map<int, std::list<int>::iterator> key2iteror;

public:
    LRUCache(int capacity_) {
        capacity = capacity_;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        } else {
            auto it = key2iteror[key];
            lru_queue.erase(it);
            lru_queue.emplace_front(key);
            key2iteror[key] = lru_queue.begin();
            return cache[key];
        }  
    }
    
    void put(int key, int value) {
        if (cache.count(key) == 0) {
            if (cache.size() == capacity) {
                int last_key = lru_queue.back();
                lru_queue.pop_back();
                auto cache_it = cache.find(last_key);
                cache.erase(cache_it);
                auto key2iterator_it = key2iteror.find(last_key);
                key2iteror.erase(key2iterator_it);
                cache[key] = value;
                lru_queue.push_front(key);
                key2iteror[key] = lru_queue.begin();
            } else {
                cache[key] = value;
                lru_queue.push_front(key);
                key2iteror[key] = lru_queue.begin();
            }
        } else {
            cache[key] = value;
            auto cache_it = key2iteror[key];
            lru_queue.erase(cache_it);
            lru_queue.push_front(key);
            key2iteror[key] = lru_queue.begin();
        }
    }
};


// 双向链表节点
class Node {
public:
    int key, val;
    Node* next, *prev;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

// 双向链表
class DoubleList {
private:
    // 头尾虚节点
    Node* head;
    Node* tail;
    // 链表元素数
    int size;

public:
    DoubleList() {
        // 初始化双向链表的数据
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // 在链表尾部添加节点 x，时间 O(1)
    void addLast(Node* x) {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    // 删除链表中的 x 节点（x 一定存在）
    // 由于是双链表且给的是目标 Node 节点，时间 O(1)
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }

    // 删除链表中第一个节点，并返回该节点，时间 O(1)
    Node* removeFirst() {
        if (head->next == tail)
            return nullptr;
        Node* first = head->next;
        remove(first);
        return first;
    }

    // 返回链表长度，时间 O(1)
    int getSize() { return size; }
};

class LRUCacheI {
private:
    // key -> Node(key, val)
    unordered_map<int, Node*> map;
    // Node(k1, v1) <-> Node(k2, v2)...
    DoubleList cache;
    // 最大容量
    int cap;

public:
    LRUCacheI(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        // 将该数据提升为最近使用的
        makeRecently(key);
        return map[key]->val;
    }

    void put(int key, int val) {
        if (map.count(key)) {
            // 删除旧的数据
            deleteKey(key);
            // 新插入的数据为最近使用的数据
            addRecently(key, val);
            return;
        }

        if (cap == cache.getSize()) {
            // 删除最久未使用的元素
            removeLeastRecently();
        }
        // 添加为最近使用的元素
        addRecently(key, val);
    }

    void makeRecently(int key) {
        Node* x = map[key];
        // 先从链表中删除这个节点
        cache.remove(x);
        // 重新插到队尾
        cache.addLast(x);
    }

    void addRecently(int key, int val) {
        Node* x = new Node(key, val);
        // 链表尾部就是最近使用的元素
        cache.addLast(x);
        // 别忘了在 map 中添加 key 的映射
        map[key] = x;
    }

    void deleteKey(int key) {
        Node* x = map[key];
        // 从链表中删除
        cache.remove(x);
        // 从 map 中删除
        map.erase(key);
    }

    void removeLeastRecently() {
        // 链表头部的第一个元素就是最久未使用的
        Node* deletedNode = cache.removeFirst();
        // 同时别忘了从 map 中删除它的 key
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
    }
};