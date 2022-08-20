#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * d == b * c) {
        cout << "0" << endl;
        return;
    }
    long long i = a * d;
    long long j = b * c;
    // j > i
    if (i > j) swap(i, j);

    if (i == 0) {
        cout << "1" << endl;
        return;
    }
    if (j % i == 0) {
        cout << "1" << endl;
        return;
    }
    cout << "2" << endl;
        return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}