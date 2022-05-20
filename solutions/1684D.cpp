#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& traps, int n, long long k) {
    if (k >= n) {
        cout << "0" << endl;
        return;
    }
    vector<int> reduce;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        reduce.push_back(traps[i] - (n - 1 - i));
        sum += traps[i];
    }
    sort(reduce.begin(), reduce.end(), greater<int>());
    for (int i = 0; i < k; i++) sum -= reduce[i];
    sum -= k * (k - 1) / 2;
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    int n;
    long long k;
    while (T--) {
        cin >> n >> k;
        vector<int> traps(n, 0);
        for (int i = 0; i < n; ++i) cin >> traps[i];
        solve(traps, n, k);
    }
    return 0;
}