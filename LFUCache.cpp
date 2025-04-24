#include "util.h"

struct LfuNode {
    int key = 0;
    int count = 0;
    int id = 0;
    LfuNode(int key_, int count_, int id_)
        : key(key_), count(count_), id(id_) {}
};

struct LfuNodeCmp {
    bool operator()(const LfuNode& a, const LfuNode& b) const {
        if (a.count != b.count) {
            return a.count < b.count;  // 优先按频率排序
        }
        return a.id < b.id;  // 频率相同则按时间戳排序
    }
};

class LFUCache {
private:
    int cap = 0;
    int id = 0;
    std::unordered_map<int, int> cache;
    std::set<LfuNode, LfuNodeCmp> lfu_queue;
    std::unordered_map<int, std::set<LfuNode, LfuNodeCmp>::iterator> keyToNode;
    const int GetId() {
        id++;
        return id;
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }
        auto lfu_it = keyToNode[key];
        LfuNode new_node = LfuNode{key, lfu_it->count+1, GetId()};
        auto[new_node_it, isInsert] = lfu_queue.insert(new_node);
        if (!isInsert) return -1;
        keyToNode[key] = new_node_it;
        lfu_queue.erase(lfu_it);
        return cache[key];
    }
    
    void put(int key, int value) {
        LfuNode new_node = LfuNode{key, 1, GetId()};
        if (cache.count(key) == 0) {
            LfuNode new_node = LfuNode{key, 1, GetId()};
            if (cache.size() == cap) {
                auto erased_it = lfu_queue.begin();
                auto erased_key = erased_it->key;
                lfu_queue.erase(erased_it);
                cache.erase(erased_key);
                keyToNode.erase(erased_key);
                auto[new_node_it, isInsert] = lfu_queue.insert(new_node);
                if (!isInsert) return;
                keyToNode[key] = new_node_it;
                cache[key] = value;
                return;
            } else {
                auto[new_node_it, isInsert] = lfu_queue.insert(new_node);
                if (!isInsert) return;
                cache[key] = value;
                keyToNode[key] = new_node_it;
                return;               
            }
        } else {
            auto lfu_it = keyToNode[key];
            LfuNode new_node = LfuNode{key, lfu_it->count+1, GetId()};
            auto[new_node_it, isInsert] = lfu_queue.insert(new_node);
            if (!isInsert) return;
            keyToNode[key] = new_node_it;
            lfu_queue.erase(lfu_it);
            cache[key] = value;
            return;
        }
    }
};
