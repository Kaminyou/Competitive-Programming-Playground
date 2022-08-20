#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    long long res = 0;
    res = v[0] + v[1] - v[n - 2] - v[n - 1];
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}