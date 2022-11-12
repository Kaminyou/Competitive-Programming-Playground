#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    vector<bool> sV;
    vector<bool> tV;
    vector<int> countS(3, 0);
    vector<int> countT(3, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            countS[0]++;
            sV.push_back(true);
        }
        else if (s[i] == 'c') {
            countS[2]++;
            sV.push_back(false);
        }
        else {
            countS[1]++;
        }
        if (t[i] == 'a') {
            countT[0]++;
            tV.push_back(true);
        }
        else if (t[i] == 'c') {
            countT[2]++;
            tV.push_back(false);
        }
        else {
            countT[1]++;
        }
        if (countS[0] < countT[0] || countS[2] > countT[2]) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (countS[i] != countT[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < sV.size(); ++i) {
        if (sV[i] != tV[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}