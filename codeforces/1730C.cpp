#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> nums(n, 0);
    vector<int> minDp(n + 1, 9);
    for (int i = 0; i < n; ++i) {
        nums[i] = s[i] - '0';
    }
    for (int i = n - 1; i >= 0; --i) {
        minDp[i] = min(minDp[i + 1], nums[i]);
    }
    string res;
    vector<int> buff(10, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < minDp[i]; ++j) {
            while (buff[j]) {
                buff[j]--;
                res.push_back(j + '0');
            }
        }
        if (nums[i] == minDp[i]) res.push_back(nums[i] + '0');
        else buff[min(9, nums[i] + 1)]++;
    }
    for (int i = 0; i < 10; ++i) {
        while (buff[i]) {
            res.push_back(i + '0');
            buff[i]--;
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}