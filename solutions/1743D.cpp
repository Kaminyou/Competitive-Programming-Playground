#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string bits;
    cin >> bits;

    // trim
    int index = 0;
    while (index < n && bits[index] == '0') index++;
    if (index == n) {
        cout << 0 << endl;
        return;
    }
    bits = bits.substr(index);
    n = bits.size();

    int firstOne = 0;
    int firstZero = 0;
    while (firstZero < n && bits[firstZero] == '1') firstZero++;
    if (firstZero == n) {
        cout << bits << endl;
        return;
    }
    int length = n - firstZero;
    string ans = bits;
    for (int i = 0; i < firstZero; ++i) {
        string s2 = bits.substr(i, length);
        string temp = bits;
        for (int j = length - 1; j >= 0; --j) {
            if (s2[j] == '1') temp[firstZero + j] = '1';
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}