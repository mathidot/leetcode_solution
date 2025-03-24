#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        std::vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int num2 = dp[a] * 2;
            int num3 = dp[b] * 3;
            int num5 = dp[c] * 5;
            dp[i] = std::min(num2, std::min(num3, num5));
            if (dp[i] == num2) a++;
            if (dp[i] == num3) b++;
            if (dp[i] == num5) c++;
            std::cout << dp[i] << std::endl;
        }
        return dp[n-1];
    }

    int nthUglyNumber_list(int n) {
        std::vector<int> ans(n, 0);
        int p2 = 0, p3 = 0, p5 = 0;
        int product2 = 1, product3 = 1, product5 = 1;
        
        for (int i = 0; i < n; i++) {
            ans[i] = std::min(std::min(product2, product3), product5);
            if (ans[i] == product2) {
                product2 = 2 * ans[p2];
                p2++;
            }
            if (ans[i] == product3) {
                product3 = 3 * ans[p3];
                p3++;
            }
            if (ans[i] == product5) {
                product5 = 5 * ans[p5];
                p5++;
            }
        }
        return ans[n-1];
    }

};

int main() {
    Solution solution;
    int res = solution.nthUglyNumber(10);
    std::cout << res << std::endl;
    return 0;
}