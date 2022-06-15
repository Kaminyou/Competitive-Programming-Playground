#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int sum = 0;
    int res = -1;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        sum += v[right];
        if (sum > s) {
            sum -= v[left];
            left++;
        }
        if (sum == s) {
            res = max(res, right - left + 1);
        }
    }
    if (res == -1) cout << res << endl;
    else cout << n - res << endl;

}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}