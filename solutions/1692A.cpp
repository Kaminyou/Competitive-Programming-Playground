#include <iostream>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    if (a < b) res++;
    if (a < c) res++;
    if (a < d) res++;
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}