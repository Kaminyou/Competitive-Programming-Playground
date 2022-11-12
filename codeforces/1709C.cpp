#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(const string& s) {
    int open = 0;
    for (auto& c : s) {
        if (c == '(') open++;
        else open--;
        if (open < 0) return false;
    }
    return open == 0;
}

void solve() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<int> unknownPosition;
    int open = n / 2;
    int close = n / 2;
    for (int i = 0; i < n; ++i) {
        auto& c = s[i];
        if (c == '(') open--;
        else if (c == ')') close--;
        else unknownPosition.push_back(i);
    }

    for (int i = 0; i < unknownPosition.size(); ++i) {
        if (i < open) s[unknownPosition[i]] = '(';
        else s[unknownPosition[i]] = ')';
    }

    bool unique = true;
    if (open > 0 && close > 0) {
        swap(s[unknownPosition[open - 1]], s[unknownPosition[open]]);
        if (isValid(s)) unique = false;
    }
    if (unique) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}