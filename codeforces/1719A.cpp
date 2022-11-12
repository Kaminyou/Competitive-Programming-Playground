#include <iostream>
using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;
    long long sum = n + m;
    if (sum & 1) cout << "Burenka" << endl;
    else cout << "Tonya" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}