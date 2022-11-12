#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

void solve(vector<string>& s) {
    for (int it = 0; it < 2; ++it) {
        while (s[0].back() == '.' && s[1].back() == '.') {
            s[0].pop_back();
            s[1].pop_back();
        }
        reverse(s[0].begin(), s[0].end());
        reverse(s[1].begin(), s[1].end());
    }

    int n = s[0].size();
    vector<vector<int>> chips(n, vector<int>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '*') chips[j][i] = 1;
        }
    }
    // dp[i][j]: if only dp[i][j] contain one chip,
    // how many moves are needed
    vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
    dp[0][0] = chips[0][1];
    dp[0][1] = chips[0][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1 + chips[i][1]);
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1 + chips[i][0]);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2);
    }
    int res = min(dp[n - 1][0], dp[n - 1][1]);
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    int n;
    vector<string> s(2);
    while (T--) {
        cin >> n >> s[0] >> s[1];
        solve(s);
    }
    return 0;
}