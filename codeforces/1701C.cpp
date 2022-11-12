#include <iostream>
#include <vector>
using namespace std;

bool criteria(vector<int>& works, int time) {
    int count = 0;
    for (auto& work : works) {
        if (work == 0) count += time / 2;
        else {
            if (time > work) count += (time - work) / 2;
            else count -= (work - time);
        }
    }
    return count >= 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> works(n, 0);
    int temp;
    int left = 0;
    int right = 0;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        works[temp - 1]++;
        right = max(right, works[temp - 1]);
    }
    if (n == m) {
        if (right == 1) {
            cout << "1" << endl;
        }
        else {
            cout << "2" << endl;
        }
        return;
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (criteria(works, mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}