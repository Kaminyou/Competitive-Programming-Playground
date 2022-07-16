#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> array(n, 0);
    for (int i = 0; i < n; ++i) cin >> array[i];
    long long sum = 0;
    int start = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (array[i] > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        cout << 0 << endl;
        return;
    }
    // [start, n - 2]
    for (int i = start; i < n - 1; ++i) {
        if (array[i] == 0) sum += 1;
        else sum += (long long)array[i];
    }
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}