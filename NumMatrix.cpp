#include "util.h"
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> pre_sum;
    
    void printMatrix(const string& name, const vector<vector<int>>& mat) {
        cout << name << ":\n";
        for (const auto& row : mat) {
            for (int val : row) {
                printf("%4d", val);
            }
            cout << "\n";
        }
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        
        cout << "==== 初始化前缀和矩阵 ====\n";
        cout << "原始矩阵尺寸: " << m << "x" << n << "\n";
        printMatrix("原始矩阵", matrix);

        // 初始化前缀和矩阵 (m+1)x(n+1)
        pre_sum.resize(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] 
                              + matrix[i-1][j-1] - pre_sum[i-1][j-1];
                
                printf("pre_sum[%d][%d] = pre_sum[%d][%d](%d) + pre_sum[%d][%d](%d) + matrix[%d][%d](%d) - pre_sum[%d][%d](%d) = %d\n",
                       i, j, 
                       i-1, j, pre_sum[i-1][j],
                       i, j-1, pre_sum[i][j-1],
                       i-1, j-1, matrix[i-1][j-1],
                       i-1, j-1, pre_sum[i-1][j-1],
                       pre_sum[i][j]);
            }
        }
        
        cout << "\n构建完成的前缀和矩阵:\n";
        printMatrix("pre_sum", pre_sum);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = pre_sum[row2+1][col2+1] - pre_sum[row2+1][col1] 
                - pre_sum[row1][col2+1] + pre_sum[row1][col1];
        
        printf("\n计算区域[(%d,%d)-(%d,%d)]:\n", row1, col1, row2, col2);
        printf("= pre_sum[%d][%d](%d)\n", row2+1, col2+1, pre_sum[row2+1][col2+1]);
        printf("- pre_sum[%d][%d](%d)\n", row2+1, col1, pre_sum[row2+1][col1]);
        printf("- pre_sum[%d][%d](%d)\n", row1, col2+1, pre_sum[row1][col2+1]);
        printf("+ pre_sum[%d][%d](%d)\n", row1, col1, pre_sum[row1][col1]);
        printf("= %d\n", sum);
        
        return sum;
    }
};

// 测试用例
int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    
    NumMatrix nm(matrix);
    nm.sumRegion(2, 1, 4, 3); // 应返回8
    nm.sumRegion(1, 1, 2, 2); // 应返回11
    nm.sumRegion(1, 2, 2, 4); // 应返回12
    
    return 0;
}