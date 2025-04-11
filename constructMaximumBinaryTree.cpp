#include "util.h"

class Solution {
private:
    TreeNode* construct(std::vector<int>::iterator left, std::vector<int>::iterator right) {
        if (left == right) return nullptr;
        auto it = std::max_element(left, right);
        TreeNode *node = new TreeNode(*it);
        node->left = construct(left, it);
        node->right = construct(it+1, right);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums.begin(), nums.end());
    }
};