#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string source, target;
    cin >> source;
    cin >> target;

    if (source[0] != target[0]) {
        cout << -1 << endl;
        return;
    }

    if (source[n - 1] != target[n - 1]) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> srcV;
    vector<vector<int>> targetV;

    int index = 0;
    while (index < n) {
        if (source[index] == '1') {
            int start = index;
            while (index + 1 < n && source[index + 1] == '1') index++;
            srcV.push_back({start, index});
        }
        index++;
    }

    index = 0;
    while (index < n) {
        if (target[index] == '1') {
            int start = index;
            while (index + 1 < n && target[index + 1] == '1') index++;
            targetV.push_back({start, index});
        }
        index++;
    }

    if (srcV.size() != targetV.size()) {
        cout << -1 << endl;
        return;
    }

    long long sum = 0;
    int m = srcV.size();
    for (int i = 0; i < m; ++i) {
        int sL = srcV[i][0];
        int sR = srcV[i][1];
        int tL = targetV[i][0];
        int tR = targetV[i][1];
        sum += abs(sL - tL);
        sum += abs(sR - tR);
    }
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}