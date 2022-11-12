#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> fives;
    vector<int> zeros;
    vector<int> twos;
    vector<int> others;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x % 10 == 0) zeros.push_back(x);
        else if (x % 5 == 0) fives.push_back(x);
        else {
            int mod = x % 20;
            int res = x % 10;
            if (res == 1 || res == 2 || res == 4 || res == 8) twos.push_back(mod);
            else others.push_back(mod);
        }
    }

    // case: have zeors
    if (zeros.size() != 0) {
        if (twos.size() > 0 || others.size() > 0) {
            cout << "NO" << endl;
            return;
        }
        int temp = zeros[0];
        for (int i = 0; i < zeros.size(); ++i) {
            if (zeros[i] != temp) {
                cout << "NO" << endl;
                return;
            }
        }
        for (int i = 0; i < fives.size(); ++i) {
            if (fives[i] != temp - 5) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }

    // case: have five
    if (fives.size() != 0) {
        if (twos.size() > 0 || others.size() > 0) {
            cout << "NO" << endl;
            return;
        }
        int temp = fives[0];
        for (int i = 0; i < fives.size(); ++i) {
            if (fives[i] != temp) {
                cout << "NO" << endl;
                return;
            }
        }
        for (int i = 0; i < zeros.size(); ++i) {
            if (zeros[i] != temp + 5) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    // check if all 1,2,4,8 in the same group
    int lessTwo = 0;
    int moreTwo = 0;
    for (auto& two : twos) {
        if (two > 10) moreTwo++;
        else lessTwo++;
    }


    int lessOthers = 0;
    int moreOthers = 0;
    for (auto& other : others) {
        if (other > 10) moreOthers++;
        else lessOthers++;
    }

    if (lessTwo > 0 && moreTwo > 0) {
        cout << "NO" << endl;
        return;
    }

    if (lessOthers > 0 && moreOthers > 0) {
        cout << "NO" << endl;
        return;
    }

    if (lessTwo > 0 && lessOthers > 0) {
        cout << "NO" << endl;
        return;
    }
    if (moreTwo > 0 && moreOthers > 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}