#include <iostream>
#include <climits>
using namespace std;

void solve() {
    int m, n;
    int aliceMax = INT_MIN;
    int bobMax = INT_MIN;
    int temp;
    cin >> m;
    while (m--) {
        cin >> temp;
        aliceMax = max(aliceMax, temp);
    }
    cin >> n;
    while (n--) {
        cin >> temp;
        bobMax = max(bobMax, temp);
    }
    // alice first
    if (aliceMax >= bobMax) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    // bob first
    if (bobMax >= aliceMax) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}