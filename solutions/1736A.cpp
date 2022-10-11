#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);

    int aOne = 0;
    int bOne = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1) aOne++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] & 1) bOne++;
    }
    // check the same
    bool same = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            same = false;
            break;
        }
    }
    if (same) {
        cout << "0" << endl;
        return;
    }
    //cout << "aOne " << aOne << " " << "bOne " << bOne << endl;
    if (aOne == bOne) {
        cout << "1" << endl;
        return;
    }
    if (bOne > aOne) {
        int diff = bOne - aOne;
        int temp = diff;
        // if b is one and a is zero, change
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0 && b[i] == 1) {
                a[i] = 1;
                diff--;
                if (diff == 0) break;
            }
        }
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                flag = true;
                break;
            }
        }
        cout << temp + flag << endl;
        return;
    }
    else {
        int diff = aOne - bOne;
        int temp = diff;
        // if b is zero and a is one, change
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1 && b[i] == 0) {
                a[i] = 0;
                diff--;
                if (diff == 0) break;
            }
        }
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                flag = true;
                break;
            }
        }
        //cout << "flag " << flag << " " << diff << endl;
        cout << temp + (int)flag << endl;
        return;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}