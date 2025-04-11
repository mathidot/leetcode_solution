#include "util.h"

class Solution {

    std::vector<std::vector<int>> res;

public:
    // 主函数，输入一组不重复的数字，返回它们的全排列
    std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
        std::list<int> track; // 记录「路径」
        bool used[nums.size()] = {false}; // 「路径」中的元素会被标记为 true，避免重复使用
        
        backtrack(nums, track, used);
        return res;
    }

private:
    // 路径：记录在 track 中
    // 选择列表：nums 中不存在于 track 的那些元素（used[i] 为 false）
    // 结束条件：nums 中的元素全都在 track 中出现
    void backtrack(const std::vector<int>& nums, std::list<int>& track, bool used[]) {
        // 触发结束条件
        if (track.size() == nums.size()) {
            res.push_back(std::vector<int>(track.begin(), track.end()));
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 排除不合法的选择
            if (used[i]) {
                // nums[i] 已经在 track 中，跳过
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            used[i] = true;
            // 进入下一层决策树
            backtrack(nums, track, used);
            // 取消选择
            track.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution solution;
    auto res = solution.permute({1,2,3});
    return 0;
}