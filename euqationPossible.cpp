#include "util.h"
#include "UF.h"

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind<char> uf;
        vector<string> equal_equations;
        vector<string> unequal_equations;
        
        // 第一步：分类等式和不等式
        for (const auto &equation : equations) {
            string op = equation.substr(1, 2);
            if (op == "!=") {
                cout << "发现不等式: " << equation << endl;
                unequal_equations.push_back(equation);
            } else {
                cout << "发现等式: " << equation << endl;
                equal_equations.push_back(equation);
            }
        }
        cout << "------------------------" << endl;

        // 第二步：处理等式
        for (const auto &equation : equal_equations) {
            char symbol_1 = equation[0];
            char symbol_2 = equation[3];
            
            cout << "处理等式 " << equation << ":" << endl;
            
            // 添加节点
            uf.add(symbol_1);
            cout << "  添加新符号: " << symbol_1 << endl;
            uf.add(symbol_2);
            cout << "  添加新符号: " << symbol_2 << endl;
            
            // 合并集合
            cout << "  合并 " << symbol_1 << " 和 " << symbol_2 << endl;
            uf.unionSets(symbol_1, symbol_2);
            
            cout << "  当前连通情况:" << endl;
            cout << "    " << symbol_1 << " 的根: " << uf.find(symbol_1) << endl;
            cout << "    " << symbol_2 << " 的根: " << uf.find(symbol_2) << endl;
            cout << "------------------------" << endl;
        }

        // 第三步：检查不等式
        for (const auto &equation : unequal_equations) {
            char symbol_1 = equation[0];
            char symbol_2 = equation[3];
            
            cout << "检查不等式 " << equation << ":" << endl;
            
            if (symbol_1 == symbol_2) return false;

            // 检查连通性
            bool connected = uf.isConnected(symbol_1, symbol_2);
            cout << "  " << symbol_1 << " 和 " << symbol_2 
                 << " 是否连通: " << (connected ? "是" : "否") << endl;
            
            if (connected) {
                cout << "  !!! 冲突发现: " << symbol_1 << " 和 " << symbol_2 
                     << " 不应连通但实际连通" << endl;
                return false;
            }
            cout << "------------------------" << endl;
        }
        
        cout << "所有不等式检查通过，无冲突" << endl;
        return true;
    }
};