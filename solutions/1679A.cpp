#include <iostream>
using namespace std;


void solve(long long n) {
    if (n < 4) {
        cout << "-1" << endl;
        return;
    }
    if ((n & 1) == 1) {
        cout << "-1" << endl;
        return;
    }

    long long k;
    k = n / 2;

    if (k == 2 || k == 3) {
        cout << "1 1" << endl;
        return;
    }

    if (k == 4 || k == 5) {
        cout << "2 2" << endl;
        return;
    }
    long long min, max;
    // k is odd
    if (k & 1) {
        max = (k - 3) / 2 + 1;
    }
    // k is even 
    else {
        max = k / 2;
    }
    for (int i = 0; i < 3; i++) {
        if (((k - 2 * i) % 3) == 0) {
            min = (k - 2 * i) / 3 + i;
        }
    }
    cout << min << " " << max << endl;
    return;
}

int main() {
    int T;
    long long n;
    cin >> T;
    while (T--) {
        cin >> n;
        solve(n);
    }
}