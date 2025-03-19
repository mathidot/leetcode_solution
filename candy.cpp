#include <vector>
#include <iostream>
using namespace std;
int candy(const vector<int>& ratings) {
    int n = ratings.size();
    std::vector<int> record(n, 0);
    int res = 0;
    if (ratings.size() <= 1) {
        return 1;
    }

    record[0] = ratings[0] > ratings[1] ? 2 : 1;

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1]) {
            record[i] = record[i-1] + 1;
        } else {
            record[i] = 1;
        }
    }

    for (int i = ratings.size()-1; i>=1; i--) {
        res += std::max(record[i], record[i-1] + 1);
    }

    return res;
}

int main() {
    int res = candy({1,2,2});
    std::cout << res << std::endl;
    return 0;
}