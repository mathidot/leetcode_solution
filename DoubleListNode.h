struct DoubleListNode {
    int val;
    DoubleListNode *prev;
    DoubleListNode *next;
    DoubleListNode() : val(0), prev(nullptr), next(nullptr) {}
    DoubleListNode(int x) : val(x), next(nullptr) {}
    DoubleListNode(int x_, DoubleListNode *prev_, DoubleListNode *next_) : val(x_), prev(prev_), next(next_) {}
};