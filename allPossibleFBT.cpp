#include "util.h"

class Solution {
private:
    unordered_map<int, vector<TreeNode *>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode *> ans;
        if (n == 0) return {};
        if (n == 1) {
            TreeNode *root = new TreeNode(0);
            ans.push_back(root);
            return ans;
        }
        if (n == 2) return {};

        for (int i = 1; i < n; i++) {
            vector<TreeNode *> leftNodes = dp.count(i) == 0 ?  allPossibleFBT(i) : dp[i];
            vector<TreeNode *> rightNodes = dp.count(n-1-i) == 0 ? allPossibleFBT(n-1-i) : dp[n-1-i];
            dp[i] = leftNodes;
            dp[n-1-i] = rightNodes;
            for (auto &left_node : leftNodes) {
                for (auto &right_node: rightNodes) {
                    TreeNode* node = new TreeNode(0);
                    node->left = left_node;
                    node->right = right_node;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};