#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    if (n <= 2) {
        cout << "YES" << endl;
        return;
    }
    vector<int> results;
    for (int i = 0; i < n - 1; ++i) {
        results.push_back(arr[i] * (arr[i + 1] / gcd(arr[i], arr[i + 1])));
    }
    for (int i = 0; i < n - 2; ++i) {
        int val = gcd(results[i], results[i + 1]);
        if (val != arr[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}