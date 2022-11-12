#include <iostream>
using namespace std;

void solve() {
    int x;
    cin >> x;
    if (x & 1) {
        x >>= 1;
        //cout << "curr x " << x << endl;
        if (x == 0) {
            cout << 3 << endl;
            return;
        }
        else {
            cout << 1 << endl;
            return;
        }
    }
    else {
        int lsb = x & (-x);
        if (x == lsb) {
            cout << lsb + 1 << endl;
        }
        else {
            cout << lsb << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}