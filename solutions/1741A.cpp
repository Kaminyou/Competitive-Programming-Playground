#include <iostream>
#include <string>
#include <vector>
using namespace std;

void toArray(string& s, vector<int>& v) {
    for (auto& c : s) {
        if (c == 'M') v[0]++;
        else if (c == 'S') v[1]++;
        else if (c == 'L') v[2]++;
        else v[3]++;
    }
}
void solve() {
    string a, b;
    cin >> a;
    cin >> b;
    vector<int> aV(4, 0); // {M, S, L, X}
    vector<int> bV(4, 0); // {M, S, L, X}
    toArray(a, aV);
    toArray(b, bV);
    // for (int i = 0; i < 4; ++i) {
    //     cout << aV[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 4; ++i) {
    //     cout << bV[i] << " ";
    // }
    // cout << endl;
    // a has L
    if (aV[2] > 0) {
        if (bV[0] > 0) cout << ">" << endl;
        else if (bV[1] > 0) cout << ">" << endl;
        else {
            if (aV[3] > bV[3]) cout << ">" << endl;
            else if (aV[3] < bV[3]) cout << "<" << endl;
            else cout << "=" << endl;
        }
        return;
    }
    // a has S
    if (aV[1] > 0) {
        if (bV[2] > 0) cout << "<" << endl;
        else if (bV[0] > 0) cout << "<" << endl;
        else {
            if (aV[3] > bV[3]) cout << "<" << endl;
            else if (aV[3] < bV[3]) cout << ">" << endl;
            else cout << "=" << endl;
        }
        return;
    }
    // a has M
    if (aV[0] > 0) {
        if (bV[2] > 0) cout << "<" << endl;
        else if (bV[1] > 0) cout << ">" << endl;
        else cout << "=" << endl;
        return;
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
