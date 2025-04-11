#include "util.h"

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            cout << "Input tree is empty" << endl;
            return nullptr;
        }
        cout << "=== Starting connection process ===" << endl;
        traverse(root->left, root->right);
        cout << "=== Connection completed ===" << endl;
        return root;
    }

    void traverse(Node* node1, Node* node2) {
        // 打印当前处理的节点对
        cout << "\n[Enter traverse] ";
        printNodePair(node1, node2);

        if (node1 == nullptr || node2 == nullptr) {
            cout << "[Base case] At least one node is null, return" << endl;
            return;
        }

        // 前序遍历：连接节点
        cout << "[Pre-order] Connecting: " << node1->val << " -> " << node2->val << endl;
        node1->next = node2;

        // 打印连接后的状态
        cout << "  After connection: ";
        printNodePair(node1, node2);

        // 递归处理子节点
        cout << "\n[Recursive call] Connecting children of " << node1->val << endl;
        traverse(node1->left, node1->right);

        cout << "\n[Recursive call] Connecting children of " << node2->val << endl;
        traverse(node2->left, node2->right);

        cout << "\n[Recursive call] Connecting cross-parent nodes between " 
             << node1->val << " and " << node2->val << endl;
        traverse(node1->right, node2->left);

        cout << "[Exit traverse] Finished processing " << node1->val << " and " << node2->val << endl;
    }

private:
    void printNodePair(Node* node1, Node* node2) {
        cout << "Node pair: ";
        if (node1) cout << node1->val; else cout << "null";
        cout << " <-> ";
        if (node2) cout << node2->val; else cout << "null";
        cout << endl;
    }
};