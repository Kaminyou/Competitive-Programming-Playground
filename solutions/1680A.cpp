#include <iostream>
using namespace std;

void solve(int l1, int r1, int l2, int r2) {
    int left = max(l1, l2);
    int right = min(r1, r2);
    if (left > right) {
        cout << l1 + l2 << endl;
    }
    else {
        cout << left << endl;
    }
}

int main() {
    int T;
    int l1, r1, l2, r2;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> l1;
        cin >> r1;
        cin >> l2;
        cin >> r2;
        solve(l1, r1, l2, r2);
    }
    return 0;
}