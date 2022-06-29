#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        cout << "? " << left << " " << mid << endl;
        int cnt = mid - left + 1;
        int inRange = 0;
        int temp;
        while (cnt--) {
            cin >> temp;
            if (temp >= left && temp <= mid) inRange++;
        }
        if (inRange & 1) right = mid;
        else left = mid + 1;
    }
    cout << "! " << left << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}