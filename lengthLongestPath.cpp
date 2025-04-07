#include "util.h"

using namespace std;

struct DirPath{
    std::string dir;
    int level;
    DirPath(): dir(""), level(0) {}
    DirPath(std::string dir_, int level_): dir(dir_), level(level_) {}
};

bool isFile(const std::string& file_name) {
    size_t dot_pos = file_name.find_last_of('.');
    return dot_pos != std::string::npos &&   // 包含点
           dot_pos != 0 &&                  // 不是以点开头（如 ".hidden"）
           dot_pos != file_name.length()-1;  // 不是以点结尾（如 "file."）
}

int lengthLongestPath(string input) {
    int ans = 0;
    vector<DirPath> dirPaths;
    for (int i = 0; i < input.size();) {
        string dir = "";
        int level = 0;
        
        // Check for "\n" sequences
        while (i < input.size() && input[i] == '\n') {
            i += 1;
        }
        
        // Check for "\t" sequences
        while (i < input.size() && input[i] == '\t') {
            level += 1;
            i += 1;
        }
        
        // Extract directory/file name
        while (i < input.size() && input[i] != '\n') {
            dir.push_back(input[i]);
            i++;
        }

        if (isFile(dir)) {
            int current_level = level - 1;
            string path = "/" + dir;
            for (auto it = dirPaths.rbegin(); it != dirPaths.rend(); it++) {
                if (!isFile(it->dir) && it->level == current_level) {
                    path = "/" + it->dir + path;
                    current_level--;
                }
            }
            ans = std::max(ans, static_cast<int>(path.length() - 1));
        }
        dirPaths.push_back(DirPath(dir, level));
    }
    return ans;
}

class Solution {
public:
    int lengthLongestPath(string input) {
        // 这个栈存储之前的父路径。实际上这里只用存父路径的长度就够了，这个优化留给你吧
        deque<int> stack;
        int maxLen = 0;
        vector<string> parts = split(input, '\n');
        for (const string& part : parts) {
            int level = part.rfind("\t") + 1;
            // 让栈中只保留当前目录的父路径
            while (level < stack.size()) {
                stack.pop_back();
            }
            stack.push_back(part.size() - level);
            // 如果是文件，就计算路径长度
            if (part.find('.') != string::npos) {
                int sum = 0;
                for (int len : stack) {
                    sum += len;
                }
                // 加上父路径的分隔符
                sum += stack.size() - 1;
                maxLen = max(maxLen, sum);
            }
        }
        return maxLen;
    }

private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main() {
    string test = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << "Test input: " << test << endl;
    int result = lengthLongestPath(test);
    cout << "\nResult: " << result << endl;
    return 0;
}