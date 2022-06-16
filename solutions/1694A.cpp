#include <iostream>
#include <string>
using namespace std;

void solve() {
    int zero, one;
    cin >> zero >> one;
    int minVal = min(zero, one);
    string res;
    for (int i = 0; i < minVal; ++i) {
        res += "01";
        zero--;
        one--;
    }
    while (zero) {
        res += "0";
        zero--;
    }
    while (one) {
        res += "1";
        one--;
    }
    cout << res << endl;

}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}