#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<bool> relations(n - 1, false);
    for (int i = 1; i < n; ++i) {
        if (v[i] * 2 > v[i - 1]) relations[i - 1] = true;
    }

    int left = 0;
    int sum = 0;
    int res = 0;
    for (int right = 0; right < n - 1; ++right) {
        sum += relations[right];
        if (right - left + 1 > k) {
            sum -= relations[left];
            left++;
        }
        if (sum == k) res += 1;
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}