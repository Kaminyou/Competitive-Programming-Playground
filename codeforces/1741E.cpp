#include <iostream>
#include <string>
#include <vector>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        if (i + v[i] <= n && dp[i - 1] == true) dp[i + v[i]] = true;
        if (i - v[i] - 1 >= 0 && dp[i - v[i] - 1] == true) dp[i] = true;
    }
    if (dp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
