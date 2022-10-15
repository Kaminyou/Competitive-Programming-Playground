#include <iostream>
#include <vector>
using namespace std;
 
void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> cnt(101, 0);
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cnt[x]++;
    }
 
    int res = 0;
    for (int i = 0; i <= 100; ++i) {
        if (cnt[i] >= 1) {
            res += min(cnt[i], c);
        }
    }
    cout << res << endl;
 
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
