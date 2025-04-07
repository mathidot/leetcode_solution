#include "util.h"

bool isNumber(const std::string& str) {
    // 匹配整数、小数、科学计数法（如 -123, 3.14, 1e-5）
    static const std::regex pattern(R"([+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?)");
    return std::regex_match(str, pattern);
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        for (string &token: tokens) {
            int num{};
            auto [ptr, ec] = std::from_chars(token.data(), token.data() + token.size(), num);
            if (ec != std::errc()) {
                if (st.empty()) return -1;
                int num1 = st.top();
                st.pop();
                if (st.empty()) return -1;
                int num2 = st.top();
                st.pop();
                if (token == "+") {
                    int num = num1 + num2;
                    st.push(num);
                } else if (token == "-") {
                    int num = num2 - num1;
                    st.push(num);
                } else if (token == "*") {
                    int num = num1 * num2;
                    st.push(num);
                } else {
                    int num = num2 / num1;
                    st.push(num);
                }
            } else {
                st.push(num);
            }
        }        
        return st.top();
    }
};