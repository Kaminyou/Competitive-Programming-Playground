#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> dp(100001, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 100001; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = 2; i * j < 100001; ++j) {
            dp[i * j] = min(dp[i * j], dp[i] + 4 + (j - 1) * 2);
        }
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int L;
        cin >> L;
        cout << "Case #" << i + 1 << ": " << dp[L] << endl;
    }
    return 0;
}

