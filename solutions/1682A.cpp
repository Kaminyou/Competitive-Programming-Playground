#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n; 
    string s;
    cin >> n;
    cin >> s;
    if (n & 1) {
        int left = (n - 1) / 2;
        int right = left;
        char c = s[left];
        while (left - 1 >= 0 && s[left - 1] == c) left--; 
        while (right + 1 < n && s[right + 1] == c) right++;
        int res = right - left + 1;
        cout << res << endl;

    }
    else {
        int left = n / 2 - 1;
        int right = left + 1;
        char c = s[left];
        while (left - 1 >= 0 && s[left - 1] == c) left--; 
        while (right + 1 < n && s[right + 1] == c) right++;
        int res = right - left + 1;
        cout << res << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}