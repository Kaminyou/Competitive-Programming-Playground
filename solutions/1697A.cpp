#include <iostream>
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sum += temp;
    }
    if (m >= sum) cout << "0" << endl;
    else cout << (sum - m) << endl;
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}