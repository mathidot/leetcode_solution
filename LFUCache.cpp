#include "util.h"

struct LfuNode {
    int key = 0;
    int count = 0;
    int id = 0;
    LfuNode(int key_, int count_, int id_)
        : key(key_), count(count_), id(id_) {}
};

struct LfuNodeCmp {
    bool operator()(LfuNode &lhs, LfuNode &rhs) {
        if (lhs.count != rhs.count) {
            return lhs.count < rhs.count;
        } else {
            return lhs.id < rhs.id;
        }
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

        if (cache.size() == cap) {
            auto lfu_it = keyToNode[key];
            Node new_node = Node{key, lfu_it->count+1, GetId()};
            
            return cache[key];
        }

    }
    
    void put(int key, int value) {
        
    }
};
