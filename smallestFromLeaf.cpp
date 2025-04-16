#include "util.h"
class Solution {
private:
    std::unordered_map<int, char> num2char = {
        {0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}, 
        {4, 'e'}, {5, 'f'}, {6, 'g'}, {7, 'h'},
        {8, 'i'}, {9, 'j'}, {10, 'k'}, {11, 'l'},
        {12, 'm'}, {13, 'n'}, {14, 'o'}, {15, 'p'},
        {16, 'q'}, {17, 'r'}, {18, 's'}, {19, 't'},
        {20, 'u'}, {21, 'v'}, {22, 'w'}, {23, 'x'},
        {24, 'y'}, {25, 'z'}
    };
    std::vector<std::string> paths;
    void traverse(TreeNode *root, std::string path) {
        if (root->left == nullptr && root->right == nullptr) {
            path.push_back('a' + root->val);
            std::reverse(path.begin(), path.end());
            paths.push_back(path);
            return;
        }

        path += num2char[root->val];
        if (root->left != nullptr) {
            traverse(root->left, path);
        }

        if (root->right != nullptr) {
            traverse(root->right, path);
        }
        return;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if (root == nullptr) return "";
        paths.clear();
        traverse(root, "");
        std::sort(paths.begin(), paths.end());
        return paths.front();
    }
};