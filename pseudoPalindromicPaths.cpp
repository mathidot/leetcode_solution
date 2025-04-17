#include "util.h"

class Solution {
private:
    int sum = 0;
    std::unordered_map<char, int> charCount;
    void traverse(TreeNode *root, int oddCount) {
        if (root->left == nullptr && root->right == nullptr) {
            charCount[root->val]++;
            if (charCount[root->val] % 2 == 1) {
                oddCount += 1;
            } else {
                oddCount -= 1;
            }
            if (oddCount <= 1) {
                sum += 1;
            }
            charCount[root->val]--;
            return;
        }

        charCount[root->val]++;
        if (charCount[root->val] % 2 == 1) {
            oddCount += 1;
        } else {
            oddCount -= 1;
        }

        if (root->left != nullptr) {
            traverse(root->left, oddCount);
        }

        if (root->right != nullptr) {
            traverse(root->right, oddCount);
        }

        charCount[root->val]--;
        return;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        sum = 0;
        charCount.clear();
        if (root == nullptr) return 0;
        traverse(root, 0);
        return sum;
    }
};