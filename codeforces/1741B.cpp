#include <iostream>
#include <string>
#include <vector>
using namespace std;


void solve() {
    int n;
    cin >> n;
    if (n == 3) {
        cout << "-1" << endl;
        return;
    }
    if (n & 1) {
        vector<int> v;
        for (int i = n ; i >= (n / 2 + 2); --i) {
            cout << i << " ";
        }
        for (int i = 1; i < (n / 2 + 2); ++i) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        for (int i = n; i >= 1; --i) {
            cout << i;
            if (i > 1) cout << " ";
        }
        cout << endl;
    }

}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
