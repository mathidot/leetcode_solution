#include "util.h"

class Solution {
public:
    string simplifyPath(string path) {    
        stack<string> st;
        int p = 0;
        
        // 第一阶段：解析路径
        while (p < path.size()) { 
            // 跳过斜杠
            while (p < path.size() && path[p] == '/') {
                p++;
            }
            
            string temp = "";
            // 收集路径段
            while (p < path.size() && path[p] != '/') {
                temp.push_back(path[p]);
                p++;
            }
            
            if (!temp.empty()) {
                if (temp == ".") {
                   // do nothing
                } else if (temp == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(temp);
                }
            }
        }
        
        // 第二阶段：构建结果
        string ans = "";
        while (!st.empty()) {
            string top_s = st.top();
            st.pop();
            ans = "/" + top_s + ans;
        }
        
        if (ans.empty()) {
            ans = "/";
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    auto ans = solution.simplifyPath("/home/user/Documents/../Pictures");
    std::cout << ans << std::endl;
    return 0;
}