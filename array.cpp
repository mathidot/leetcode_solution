#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int trap_1(const vector<int>& height) {
    int ans = 0;
    std::vector<int> leftMax(height.size(), 0);
    std::vector<int> rightMax(height.size(), 0);
    int lm = 0, rm = 0;
    for (int i = 0; i < height.size(); i++) {
        if (i == 0) {
            leftMax[0] = 0;
            rightMax[height.size()-1] = 0;
            continue;
        }
        lm = std::max(lm, height[i-1]);
        rm = std::max(rm, height[height.size()-i]);
        leftMax[i] = lm;
        rightMax[height.size()-1-i] = rm;
    }

    for (int i = 0; i < height.size(); i++) {
        printf("%d ", leftMax[i]);
    }
    printf("\n");
    for (int i = 0; i < height.size(); i++) {
        printf("%d ", rightMax[i]);
    }
    printf("\n");

    for (int i = 0; i < height.size(); i++) {
        if (leftMax[i] <= height[i] || rightMax[i] <= height[i]) {
            continue;
        }

        ans += std::min(leftMax[i], rightMax[i]) - height[i];

    }
    return ans;
}

int trap(const vector<int>& height) {
    int ans = 0;
    int lm = 0, rm = 0;
    int left = 0, right = height.size()-1;

    while (left <= right) {
        lm = left == 0 ? 0 : std::max(lm, height[left-1]);
        rm = right == height.size() - 1 ? 0 : std::max(rm, height[right+1]);
        if (lm <=height[right] || lm <= rm) {
            ans += height[left] > lm ? 0 : lm - height[left];
            left++;
        } else {
            ans += height[right] > rm ? 0 : rm - height[right];
            right--;
        }
    }

    return ans;
}

int char2Int(char c) {
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        printf("invalid character\n");
        return -1;
    }
}

int romanToInt(const string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'I') {
            if (i == s.size() - 1) {
                ans += 1;
                return ans;
            } else if (s[i+1] == 'V') {
                ans += 4;
                i++;
            } else if (s[i+1] == 'X') {
                ans += 9;
                i++;
            } else {
                ans += 1;
            }
        } else if (s[i] == 'X') {
            if (i == s.size() - 1) {
                ans += 10;
                return ans;
            } else if (s[i+1] == 'L') {
                ans += 40;
                i++;
            } else if (s[i+1] == 'C') {
                ans += 90;
                i++;
            } else {
                ans += 10;
            }
        } else if (s[i] == 'C') {
            if (i == s.size() - 1) {
                ans += 100;
                return ans;
            } else if (s[i+1] == 'D') {
                ans += 400;
                i++;
            } else if (s[i+1] == 'M') {
                ans += 900;
                i++;
            } else {
                ans += 100;
            }
        } else {
            ans += char2Int(s[i]);
        }
    }
    return ans;
}

int head(int num) {
    int ans = num;
    while(num > 0) {
        ans = num;
        num /= 10;
    }
    return ans;
}


string intToRoman(int num) {
    string ans = "";
    while (num >= 1000) {
        num -= 1000;
        ans.append("M");
    }
    
    if (head(num) == 9 && num > 100) {
        num -= 900;
        ans.append("CM");
    }

    if (num >= 500) {
        num -= 500;
        ans.append("D");
    }

    if (head(num) == 4 && num > 100) {
        num -= 400;
        ans.append("CD");
    }        

    while (num >= 100)
    {
        num -= 100;
        ans.append("C");
    }
        
    if (head(num) == 9 && num > 10) {
        num -= 90;
        ans.append("XC");
    }

    if (num >= 50) {
        num -= 50;
        ans.append("L");
    }

    if (head(num) == 4 && num > 10) {
        num -= 40;
        ans.append("XL");
    }        

    while (num >= 10) {
        num -= 10;
        ans.append("X");
    }

    if (head(num) == 9) {
        num -= 9;
        ans.append("IX");
        return ans;
    }

    if (num >= 5) {
        num -= 5;
        ans.append("V");
    }

    if (num == 4) {
        num -= 4;
        ans.append("IV");
        return ans;
    }

    while (num > 0) {
        num--;
        ans.append("I");
    }

    return ans;
}


int main(int argc, char **argv) {
    string s = intToRoman(3749);
    std::cout << s << std::endl;
    return 0;
}