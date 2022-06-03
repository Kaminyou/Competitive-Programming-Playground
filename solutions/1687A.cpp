#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> values(n, 0);
    for (int i = 0; i < n; ++i) cin >> values[i];
    if (k >= n) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) sum += values[i];
        long long up = k - 1;
        long long down = k - n;
        sum += (up + down) * (long long)n / 2;
        cout << sum << endl;
        return;
    }
    else {
        long long curr = 0;
        for (int i = 0; i < k; ++i) curr += values[i];
        long long maxVal = curr;
        for (int i = k; i < n; ++i) {
            curr += values[i];
            curr -= values[i - k];
            maxVal = max(maxVal, curr);
        }
        long long up = k - 1;
        maxVal += (up + 0) * (up + 1) / 2;
        cout << maxVal << endl;
        return;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}