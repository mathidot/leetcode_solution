#include "util.h"

class StockSpanner {
private:
    vector<int> prices;
    stack<int> s;
public:
    StockSpanner() {}
    
    int next(int price) {
        prices.push_back(price);
        while (!s.empty() && prices[s.top()] <= price) {
            s.pop();
        }
        int top_idx = s.empty() ? -1 : s.top();
        s.push(prices.size()-1);
        return top_idx == -1 ? prices.size() : prices.size()-1-top_idx;
    }
};