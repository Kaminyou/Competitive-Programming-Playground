#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<int> deck(n, 0);
    for (int i = 0; i < n; ++i) cin >> deck[i];
    cin >> m;
    long long sum = 0;
    int temp;
    while (m--) {
        cin >> temp;
        sum += temp;
    }
    sum %= n;
    int ans = deck[sum];
    cout << ans << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}