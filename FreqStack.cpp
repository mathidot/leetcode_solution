#include "util.h"

class FreqStack {
    int maxFreq = 0;
    unordered_map<int, int> valToFreq;
    unordered_map<int, stack<int>> freqToVals;

    // 新增的打印方法
    void printState(const string& op, int val = -1) {
        cout << "\n=== After " << op;
        if (val != -1) cout << " " << val;
        cout << " ===" << endl;
        
        cout << "maxFreq: " << maxFreq << endl;
        
        cout << "valToFreq: ";
        for (auto& [v, f] : valToFreq) {
            cout << v << ":" << f << " ";
        }
        cout << endl;
        
        cout << "freqToVals:" << endl;
        for (auto& [f, s] : freqToVals) {
            cout << "  freq " << f << ": [";
            // 注意：stack不能直接遍历，这里只显示顶部元素
            if (!s.empty()) cout << s.top() << "](size:" << s.size() << ")";
            else cout << "](empty)";
            cout << endl;
        }
    }

public:
    void push(int val) {
        // 原push逻辑保持不变
        int freq = valToFreq.count(val) ? valToFreq[val] + 1 : 1;
        valToFreq[val] = freq;
        freqToVals[freq].push(val);
        maxFreq = max(maxFreq, freq);
        
        // 添加打印
        printState("push", val);
    }

    int pop() {
        // 原pop逻辑保持不变
        int v = freqToVals[maxFreq].top();
        freqToVals[maxFreq].pop();
        valToFreq[v]--;
        if (freqToVals[maxFreq].empty()) {
            maxFreq--;
        }
        
        // 添加打印
        printState("pop");
        cout << "Return: " << v << endl;
        return v;
    }
};

int main() {
    FreqStack fs;
    fs.push(3);
    fs.push(3);
    fs.push(1);
    fs.push(3);
    
    fs.pop();
    fs.pop();
    fs.pop();
    fs.pop();
    
    return 0;
}