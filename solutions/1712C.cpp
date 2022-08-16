#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];

    unordered_map<int, vector<int>> num2idx;
    unordered_map<int, int> num2real;
    for (int i = 0; i < n; ++i) {
        num2idx[v[i]].push_back(i);
        num2real[v[i]] = v[i];
    }

    for (auto& element : num2idx) {
        if (element.second.size() > 1) {
            int m = element.second.size();
            for (int i = 1; i < m; ++i) {
                if (element.second[i] - element.second[i - 1] != 1) {
                    num2real[element.first] = 0;
                    break;
                }
            }
        }
    }

    int currentMax = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (num2real[v[i]] > currentMax) {
            num2real[v[i]] = 0;
            currentMax = 0;
        }
        else {
            currentMax = num2real[v[i]];
        }
    }
    int res = 0;
    for (auto& element : num2real) {
        if (element.second == 0) res++;
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}