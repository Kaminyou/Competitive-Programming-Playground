#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long res = 0;
    res += n;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '1' && s[i - 1] == '0') res += i;
        else if (s[i] == '0' && s[i - 1] == '1') res += i;
    }
    cout << res << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}