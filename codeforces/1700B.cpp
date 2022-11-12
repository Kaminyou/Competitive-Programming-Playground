#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    string num;
    int n;
    cin >> n;
    cin >> num;
    if (num[0] != '9') {
        string out = num;
        for (int i = 0; i < n; ++i) {
            out[i] = '9' - num[i] + '0';
        }
        cout << out << endl;
        return;
    }
    string out = num;
    for (int i = 0; i < n; ++i) {
        out[i] = '9' - num[i] + '0';
    }
    string add = num;
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) add[i] = '2';
        else add[i] = '1';
    }

    int sum = 0;
    int cache = 0;
    string res = "";
    for (int i = n - 1; i >= 0; --i) {
        cache += (out[i] - '0') + (add[i] - '0');
        res.push_back((cache % 10) + '0');
        cache /= 10;
    }
    if (cache) {
        res.push_back((cache % 10) + '0');
    }
    reverse(res.begin(), res.end());
    cout << res << endl;

}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}