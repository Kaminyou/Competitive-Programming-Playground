#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long x, y, z;
        x = 3 * c + 3 * b + a;
        y = c + b;
        z = c;
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}