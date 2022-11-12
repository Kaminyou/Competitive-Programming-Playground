#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string temp;
    vector<int> count(26, 0);
    int lines = 2 * n + 1;
    while (lines--) {
        cin >> temp;
        for (auto c : temp) {
            count[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (count[i] & 1) {
            char c = i + 'a';
            cout << c << endl;
            return;
        }
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