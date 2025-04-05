#include "util.h"
struct Element {
    char c;
    int count;
    Element(char c_, int count_): c(c_), count(count_) {}
    
    bool operator()(const Element &lhs, const Element &rhs) {
        return lhs.count < rhs.count;
    }

    bool operator<(const Element &other) const {
        if (count != other.count) 
            return count < other.count;
        return c < other.c;
    }
};

class WindowCount {
public:
    std::set<Element> window;
    
    void printWindow() const {
        cout << "Current window: [";
        for (const auto& e : window) {
            cout << "(" << e.c << ":" << e.count << ") ";
        }
        cout << "]" << endl;
    }

    void AddChar(char c) {
        cout << "\nAdding char: '" << c << "'" << endl;
        auto it = std::find_if(window.begin(), window.end(), [&c](const Element &e) {
            return e.c == c;
        });
        
        if (it == window.end()) {
            cout << "  New character, inserting (" << c << ":1)" << endl;
            window.insert(Element{c,1});
        } else {
            int c_count = it->count;
            cout << "  Existing character (" << c << ":" << c_count << "), incrementing count" << endl;
            window.erase(it);
            window.insert(Element{c, c_count + 1});
        }
        printWindow();
    }

    void RemoveChar(char c) {
        cout << "\nRemoving char: '" << c << "'" << endl;
        auto it = std::find_if(window.begin(), window.end(), [&c](const Element &e) {
            return e.c == c;
        });
        
        if (it == window.end()) {
            cout << "  Character not found" << endl;
            return;
        } else {
            int c_count = it->count;
            cout << "  Found character (" << c << ":" << c_count << "), decrementing count" << endl;
            window.erase(it);
            c_count -= 1;
            if (c_count != 0) {
                cout << "  Updating count to " << c_count << endl;
                window.insert(Element{c, c_count});
            } else {
                cout << "  Count reached 0, removing completely" << endl;
            }
        }
        printWindow();
    }

    int GetMinCount() const {
        int min = window.empty() ? 0 : window.begin()->count;
        cout << "  Current min count: " << min << endl;
        return min;
    }

    void GetMaxCount() const {
        int max = window.empty() ? 0 : window.rbegin()->count;
        cout << "  Current max count: " << max << endl;
    }

    size_t GetWindowSize() const {
        return window.size();
    }
};

class Solution {
public:
    int longestKSubstring(string s, int k, int count) {
        cout << "Starting search with k = " << k << endl;
        WindowCount window;
        int ans = numeric_limits<int>::min();
        int left = 0, right = 0;
        
        cout << "Initial window: empty" << endl;
        
        while (right < s.size()) {
            char rc = s[right];
            cout << "\n--- Processing position " << right << " ('" << rc << "') ---" << endl;
            
            window.AddChar(rc);
            right++;
            
            while (left < right && window.GetWindowSize() > count) {
                char lc = s[left];
                cout << "  Window min count > k, removing leftmost char '" << lc << "' at pos " << left << endl;
                window.RemoveChar(lc);
                left++;
            }
            
            if (window.GetMinCount() >= k && window.GetWindowSize() == count) {
                int current_len = right - left;
                cout << "  Valid window found: length = " << current_len << " [" << left << "," << right << ")" << endl;
                ans = max(ans, current_len);
            } else {
                cout << "  Invalid window: min count < k" << endl;
            }
        }

        cout << "\nFinal result: ";
        return ans == numeric_limits<int>::min() ? 0 : ans;
    }

    int longestSubstring(string s, int k) {
        int len = 0;
        for (int i = 1; i <= 26; i++) {
            // 限制窗口中只能有 i 种不同字符
            len = std::max(len, longestKSubstring(s, k, i));
        }
        return len;
    }
};
