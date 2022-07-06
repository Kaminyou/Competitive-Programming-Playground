#include <iostream>
#include <string>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    // if n is odd
    if (n & 1) {
        cout << "-1" << endl;
        return;
    }
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long shift = 0;
    string bits = "";
    while (n) {
        if (n & 1) bits.push_back('1');
        else bits.push_back('0');
        n >>= 1;
    }
    int size = bits.size();
    for (int i = 0; i < size - 1; ++i) {
        if (bits[i + 1] == '0') {
            continue;
        }
        else {
            a += (1 << i);
            b += (1 << i);
        }
    }
    cout << a << " " << b << " " << c << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}