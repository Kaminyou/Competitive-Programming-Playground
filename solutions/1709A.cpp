#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int key;
    cin >> key;
    vector<int> doors(3, 0);
    for (int i = 0; i < 3; ++i) cin >> doors[i];

    vector<bool> open(3, false);
    open[key - 1] = true;

    // first try
    int nextKey = -1;
    if (doors[key - 1] != 0) {
        nextKey = doors[key - 1];
        doors[key - 1] = 0;
    }
    else {
        cout << "NO" << endl;
        return;
    }

    // second try
    if (doors[nextKey - 1] != 0) {
        nextKey = doors[nextKey - 1];
        doors[nextKey - 1] = 0;
    }
    else {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}