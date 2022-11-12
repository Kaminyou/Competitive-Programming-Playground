#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    if (n & 1) {
        cout << "Mike" << endl;
        return;
    }
    int first = v[0];
    bool allSame = true;
    for (int i = 1; i < n; ++i) {
        if (v[i] != first) {
            allSame = false;
            break;
        }
    }
    if (allSame) {
        cout << "Joe" << endl;
        return;
    }
    int minVal = INT_MAX;
    int minIdx = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i] < minVal) {
            minVal = v[i];
            minIdx = i;
        }
    }
    if (minIdx & 1) {
        cout << "Mike" << endl;
        return;
    }
    cout << "Joe" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}