#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() == 2) {
            cout << s[1] << endl;
        }
        else {
            vector<bool> have(10, false);
            for (auto c : s) have[c - '0'] = true;
            for (int i = 0; i < 10; i++) {
                if (have[i]) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}