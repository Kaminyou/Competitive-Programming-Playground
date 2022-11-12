#include <iostream>
#include <string>
using namespace std;

void solve(const string& s) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += (s[i] - '0');
    }
    for (int i = 3; i < 6; i++) {
        sum -= (s[i] - '0');
    }
    if (sum == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}