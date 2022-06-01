#include <iostream>
#include <string>
#include <climits>
using namespace std;

void solve() {
    int n, k;
    string binary;
    cin >> n >> k;
    cin >> binary;
    
    int sum = 0;
    int leftIdx = INT_MAX;
    int rightIdx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (binary[i] == '1') {
            if (i == 0) sum += 10;
            else if (i == n - 1) sum += 1;
            else sum += 11;
            leftIdx = min(leftIdx, i);
            rightIdx = max(rightIdx, i);
        }
    }
    //cout << "curr " << sum << " " << k << endl;
    if (sum == 0 || k == 0) {
        cout << sum << endl;
        return;
    }
    if (leftIdx == rightIdx) {
        if (rightIdx == n - 1) {
            cout << sum << endl;
            return;
        }
        int moveLeft = leftIdx;
        int moveRight = n - rightIdx - 1;
        if (k >= moveRight && leftIdx == 0) {
            cout << sum - 9 << endl;
            return;
        }
        if (k >= moveRight) {
            cout << sum - 10 << endl;
            return;
        }
        if (k >= moveLeft && moveLeft != 0) {
            cout << sum - 1 << endl;
            return;
        }
        else {
            cout << sum << endl;
            return;
        }
    }

    int moveLeft = leftIdx;
    int moveRight = n - rightIdx - 1;
    if (k >= moveRight && moveRight != 0) {
        k -= moveRight;
        sum -= 10;
    }
    if (k >= moveLeft && moveLeft != 0) sum -= 1;
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}