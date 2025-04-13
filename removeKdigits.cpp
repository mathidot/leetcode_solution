#include "util.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0"; // 全部删除
        
        stack<char> s;
        
        for (char c : num) {
            while (k > 0 && !s.empty() && s.top() > c) {
                s.pop();
                k--;
            }
            s.push(c);
        }
        
        // 如果还有剩余k，从末尾删除（处理单调递增情况）
        while (k-- > 0) {
            s.pop();
        }
        
        // 构建结果字符串
        string ans;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // 删除前导零
        size_t start = ans.find_first_not_of('0');
        return (start == string::npos) ? "0" : ans.substr(start);
    }
};