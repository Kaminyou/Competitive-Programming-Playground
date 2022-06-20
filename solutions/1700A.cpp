#include <iostream>
using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;
    long long res = 0;
    res += ((m * (m - 1)) / 2);
    res += (m * ((1 + n) * n / 2));
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}