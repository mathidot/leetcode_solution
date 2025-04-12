#include "util.h"

TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    return root;
}

// 测试函数：打印树结构
void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;
    string indent(depth * 2, ' ');
    cout << indent << root->val << endl;
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}

class Codec {
private:
    TreeNode* deserialize(deque<string> &tokens) {
        if (tokens.empty()) return nullptr;
        string val = tokens.front();
        tokens.pop_front();
        if (val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(tokens);
        root->right = deserialize(tokens);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#,";
        string code = std::to_string(root->val) + ",";
        string left_code = serialize(root->left);
        string right_code = serialize(root->right);
        code.append(left_code);
        code.append(right_code);
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        deque<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        return deserialize(tokens);
    }
};

int main() {
    Codec codec;
    // 测试1：序列化
    TreeNode* root = createTestTree();
    cout << "=== Original Tree Structure ===" << endl;
    printTree(root);
    
    string serialized = codec.serialize(root);
    cout << "\n=== Final Serialized String ===" << endl;
    cout << serialized << endl;
}