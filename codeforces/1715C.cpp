#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long res = (long long)n * (n + 1) / 2;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 1; i < n; ++i) {
        if (v[i] != v[i - 1]) {
            res += (long long)i * (n - i);
        }
    }

    while (m--) {
        int position, x;
        cin >> position >> x;
        position--;
        if (position - 1 >= 0) {
            if (v[position] != v[position - 1]) {
                res -= (long long)position * (n - position);
            }
        }
        if (position + 1 < n) {
            if (v[position] != v[position + 1]) {
                res -= (long long)(position + 1) * (n - position - 1);
            }
        }
        v[position] = x;
        if (position - 1 >= 0) {
            if (v[position] != v[position - 1]) {
                res += (long long)position * (n - position);
            }
        }
        if (position + 1 < n) {
            if (v[position] != v[position + 1]) {
                res += (long long)(position + 1) * (n - position - 1);
            }
        }
        cout << res << endl;
    }

    return 0;
}