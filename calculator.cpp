#include "util.h"

class Solution {
private:
    std::unordered_map<int, int> leftBracketToRight;
    void preCalculateRightBracket(std::string s) {
        leftBracketToRight.clear();
        std::stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                leftBracketToRight[st.top()] = i;
                st.pop();
            }
        }
        for (auto p: leftBracketToRight) {
            std::cout << "left: " << p.first
                << " right: " << p.second << std::endl;
        }
    }

    int _calculate(std::string s, int left, int right) {
        std::stack<int> st;
        char pre_op = '+';
        int curr_num = 0;
        for (int i = left; i < right; i++) {
            char c = s[i];
            if (std::isdigit(s[i])) {
                curr_num = 10 * curr_num + (c - '0');
            }
            if (c == '(') {
                std::cout << "recursive call calculate :"
                    << "left " << i+1 << " right " << leftBracketToRight[i] << endl;
                curr_num = _calculate(s, i+1, leftBracketToRight[i]);
                i = leftBracketToRight[i];
                std::cout << "curr_num is " << curr_num << ", i move to " << i << std::endl;
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == right-1) {
                int num = 0;
                switch (pre_op)
                {
                case '+':
                    st.push(curr_num);
                    break;
                case '-':
                    st.push(-curr_num);
                    break;
                case '*':
                    num = curr_num * st.top();
                    st.pop();
                    st.push(num);
                    break;
                case '/':
                    num = st.top() / curr_num;
                    st.pop();
                    st.push(num);
                    break;
                }
                pre_op = c;
                curr_num = 0;
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }

public:
    int calculate(string s) {
        preCalculateRightBracket(s);
        return _calculate(s, 0, s.length());
    }
};

class SolutionI {
private:
    void get_into_stack(stack<int>& nums, char& sign, int&num, char c='+'){
        switch(sign){
            case '+': nums.push(num); break;
            case '-': nums.push(-num); break;
        }
        sign = c;
        num = 0;
    }

    int sum_stack(stack<int> nums){
        int sum = 0;
        while(!nums.empty()){
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
public:
    int calculate(string s) {
        int index = 0;
        return helper(s, index);
    }

    int helper(string s, int &index) {
        stack<int> nums;
        char sign = '+';
        int num = 0;
        while (index < s.size()) {
            char c = s[index++];
            if (c == ' ') continue;
            else if (std::isdigit(c)) num = num * 10 + (c - '0');
            else if (c == '(') num = helper(s, index);
            else if (c == ')') break;
            else get_into_stack(nums, sign, num, c);
        }
        get_into_stack(nums, sign, num);
        return sum_stack(nums);
    }
};