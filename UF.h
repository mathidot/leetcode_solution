#include "util.h"

class UF {
private:
    // 连通分量个数
    int _count;
    // 存储每个节点的父节点
    vector<int> parent;

public:
    // n 为图中节点的个数
    UF(int n) {
        this->_count = n;
        this->parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // 将节点 p 和节点 q 连通
    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ)
            return;
        
        parent[rootQ] = rootP;
        // 两个连通分量合并成一个连通分量
        _count--;
    }

    // 判断节点 p 和节点 q 是否连通
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 返回图中的连通分量个数
    int count() {
        return _count;
    }
};

#include <unordered_map>
#include <vector>
#include <limits> // 用于 std::numeric_limits

template <typename T>
class UnionFind {
private:
    std::unordered_map<T, T> parent;
    int _count = 0;

    // 定义一个不可能的值作为错误码
    static constexpr T ERROR_CODE = static_cast<T>(-1);

public:
    // 检查元素是否存在
    bool contains(const T& x) const {
        return parent.find(x) != parent.end();
    }

    // 添加新元素
    void add(const T& x) {
        if (!contains(x)) {
            parent[x] = x;
            _count++;
        }
    }

    // 查找根节点，如果不存在返回ERROR_CODE
    T find(const T& x) {
        if (!contains(x)) {
            return ERROR_CODE;
        }
        
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    // 合并两个集合
    bool unionSets(const T& x, const T& y) {
        if (!contains(x)) add(x);
        if (!contains(y)) add(y);
        
        T rootX = find(x);
        T rootY = find(y);
        
        // 检查是否查找失败
        if (rootX == ERROR_CODE || rootY == ERROR_CODE) {
            return false;
        }
        
        if (rootX == rootY) return true;

        parent[rootY] = rootX;
        _count--;
        return true;
    }

    // 检查两个元素是否连通
    bool isConnected(const T& x, const T& y) {
        T rootX = find(x);
        T rootY = find(y);
        
        // 任一元素不存在或查找失败都认为不连通
        if (rootX == ERROR_CODE || rootY == ERROR_CODE) {
            return false;
        }
        return rootX == rootY;
    }

    // 返回连通分量数量
    int count() const {
        return _count;
    }

    // 获取所有根节点
    std::vector<T> getRoots() const {
        std::vector<T> roots;
        for (const auto& [key, val] : parent) {
            if (key == val) {
                roots.push_back(key);
            }
        }
        return roots;
    }
};