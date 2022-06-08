#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int base = (n - 6) / 3 + 1;
    int order = (n - 6) % 3;

    int a, b, c;
    if (order == 0) {
        a = base;
        b = base + 1;
        c = base + 2;
    }
    else if (order == 1) {
        a = base;
        b = base + 1;
        c = base + 3;   
    }
    else {
        a = base;
        b = base + 2;
        c = base + 3;
    }
    cout << b << " " << c << " " << a << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}