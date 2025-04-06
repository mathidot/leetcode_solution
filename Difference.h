# include "util.h"

class Difference {
private:
    std::vector<int> diff;
public:
    Difference(vector<int> &nums) {
        diff = vector<int>(nums.size());
        // 根据初始数组构造差分数组
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i-1];
        }
    }

    // 给闭区间[i,j]增加val
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j+1] -= val;
        }
    }

    // return result
    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < res.size(); i++) {
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};
