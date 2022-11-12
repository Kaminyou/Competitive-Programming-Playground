#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> v(n, false);
    vector<int> store(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> store[i];
    }

    int index = n - 1;
    bool flag = false;
    while (index >= 0) {
        if (v[store[index] - 1]) {
            flag = true;
            break;
        }
        v[store[index] - 1] = true;
        index--;
    }
    if (!flag) cout << "0" << endl;
    else {
        cout << index + 1 << endl;
    }
    
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}