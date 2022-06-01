#include <iostream>
using namespace std;

void solve() {
    int n, temp;
    cin >> n;
    int even = 0;
    int odd = 0;
    while (n--) {
        cin >> temp;
        if (temp & 1) odd++;
        else even++;
    }
    int ans = min(odd, even);
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