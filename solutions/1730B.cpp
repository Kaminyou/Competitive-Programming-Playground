#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool inInterval(int l1, int r1, int l2, int r2) {
    int left = max(l1, l2);
    int right = min(r1, r2);
    if (left > right) return false;
    return true;
}

bool criteria(int time, vector<int>& position, vector<int>& dressTime, int n, int& pos) {
    int left = INT_MIN;
    int right = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (time < dressTime[i]) return false;
        int remain = time - dressTime[i];
        int currentLeft = position[i] - remain;
        int currentRight = position[i] + remain;

        
        if (!inInterval(currentLeft, currentRight, left, right)) return false;
        //if (currentRight > right) return false;
        left = max(currentLeft, left);
        right = min(currentRight, right);
    }
    pos = left;
    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<int> position(n, 0);
    vector<int> dressTime(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> position[i];
        position[i] *= 2;
    }
    for (int i = 0; i < n; ++i) {
        cin >> dressTime[i];
        dressTime[i] *= 2;
    }

    int left = -1;
    int right = 1e9 + 7;
    int pos;
    int index = 0;
    while (right > left) {
        
        int mid = left + (right - left) / 2;
        if (criteria(mid, position, dressTime, n, pos)) {
            right = mid;
        }
        else left = mid + 1;
    }
    int out = pos / 2;
    if (pos & 1) {
        cout << out << ".5" << endl;
    }
    else {
        cout << out << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}