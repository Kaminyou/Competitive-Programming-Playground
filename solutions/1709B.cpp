#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; ++i) cin >> heights[i];
    // 0  1 2 3 4 5  6
    // 10 8 9 6 8 12 7
    // 0  2 2 5 5 5  10
    // 7  7 6 6 4 0  0
    LL forwardSum = 0;
    vector<LL> forward(n, 0);
    for (int i = 1; i < n; ++i) {
        if (heights[i] < heights[i - 1]) forwardSum += heights[i - 1] - heights[i];
        forward[i] = forwardSum;
    }

    LL backwardSum = 0;
    vector<LL> backward(n, 0);
    for (int i = n - 2; i >= 0; --i) {
        if (heights[i] < heights[i + 1]) backwardSum += heights[i + 1] - heights[i];
        backward[i] = backwardSum;
    }

    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        if (t > s) {
            LL res = forward[t - 1] - forward[s - 1];
            cout << res << endl;
        }

        else {
            LL res = backward[t - 1] - backward[s - 1];
            cout << res << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}