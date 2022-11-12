#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] -= (i + 1);
    }
    int plus = 0;
    int right = 0;
    long long res = 0;
    for (int left = 0; left < n; ++left) {
        // move right
        while (right + 1 < n && arr[right + 1] + plus >= 0) right++;
        res += (right - left + 1);
        plus++;
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}