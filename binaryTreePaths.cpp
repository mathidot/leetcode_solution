#include "util.h"

class Solution {
private:
    void _binaryTreePaths(TreeNode *root, vector<string> &paths, std::string path) {
        if (root->left == nullptr && root->right == nullptr) {
            path.append(std::to_string(root->val));
            paths.push_back(path);
            return;
        }
        path += std::to_string(root->val) + "->";
        if (root->left != nullptr)
            _binaryTreePaths(root->left, paths, path);
        if (root->right != nullptr)
            _binaryTreePaths(root->right, paths, path);
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) return ans;
        _binaryTreePaths(root, ans, "");
        return ans;
    }
};