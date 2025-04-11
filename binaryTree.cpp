#include "util.h"

/*
void backtrack(std::vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		used[i] = true;
		track.push_back(nums[i]);
		backtrack(nums);
		track.pop_back();
		used[i] =false;
	}
}
*/

void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
	int m = grid.size(), n = grid.front().size();
	if (i < 0 || j < 0 || i >=m || j >= n) {
		return;
	}
	if (grid[i][j] == 0) {
		return;
	}
	
	grid[i][j] = 0;
	dfs(grid, i+1, j);
	dfs(grid, i, j+1);
	dfs(grid, i-1, j);
	dfs(grid, i, j-1);
}

// 动态规划关注整颗子树、回溯算法关注节点间的树枝、DFS算法关注单个节点‘

// 层序遍历

void levelTraverse(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	
	std::queue<TreeNode*> q;
	q.push(root);
	
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			TreeNode* cur = q.front();
			q.pop();
			if (cur->left != nullptr) {
				q.push(cur->left);
			}
			if (cur->right != nullptr) {
				q.push(cur->right);
			}
		}
	}
}

class Solution {
private:
	vector<vector<int>> res;
	
	void traverse(vector<TreeNode*> &curLevelNodes) {
		if (curLevelNodes.empty()) return;
		vector<int> nodeValues;
		vector<TreeNode*> nextLevelNodes;
		for (TreeNode* node: curLevelNodes) {
            if (node->left != NULL) {
                nextLevelNodes.push_back(node->left);
            }
            if (node->right != NULL) {
                nextLevelNodes.push_back(node->right);
            }
		}
		
		res.push_back(nodeValues);
		traverse(nextLevelNodes);
	}
	
public:
	vector<vector<int>> levelTraverse(TreeNode* root) {
		if (root == nullptr) {
			return res;
		}
		vector<TreeNode*> nodes;
		nodes.push_back(root);
		traverse(nodes);
		return res;
	}
}