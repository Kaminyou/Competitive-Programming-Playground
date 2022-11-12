#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n, 0);
    for (int i = 0; i < n; ++i) cin >> numbers[i];

    vector<int> dp(n, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = i - 1; j >= max(0, i - 256); --j) {
            if ((numbers[i] ^ j) > (numbers[j] ^ i)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}