#include "util.h"
#include "UF.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        const int m = board.size();
        const int n = board[0].size();
        const int mn = m * n;
        
        // 初始化并查集，多一个哨兵节点用于标记边界'O'
        UF uf(mn + 1);
        
        // 四个方向数组
        constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        // 边界'O'连接到哨兵节点
                        uf.union_(i * n + j, mn);
                    } else {
                        // 检查四个方向
                        for (const auto& [dx, dy] : dirs) {
                            int ni = i + dx;
                            int nj = j + dy;
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n && 
                                board[ni][nj] == 'O') {
                                uf.union_(i * n + j, ni * n + nj);
                            }
                        }
                    }
                }
            }
        }
        
        // 修改被围绕的区域
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !uf.connected(i * n + j, mn)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};