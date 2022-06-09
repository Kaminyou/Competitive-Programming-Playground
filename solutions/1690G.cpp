#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> speed(n, 0);
    set<int> st;
    for (int i = 0; i < n; ++i) {
        cin >> speed[i];
        if (st.empty() || speed[i] < speed[*st.rbegin()]) st.insert(i);
    }

    for (int i = 0; i < m; ++i) {
        int k, d;
        cin >> k >> d;
        k--;
        speed[k] -= d;
        // check the one in st whose index <= k
        // get > and move back
        auto it = st.upper_bound(k);
        if (it != st.begin()) {
            it--;
            if (k == *it || speed[*it] > speed[k]) {
                st.insert(k);
            }
        }
        else {
            st.insert(k);
        }

        // remove the element whose index > k 
        // but value >= speed[k]
        while (true) {
            auto it = st.upper_bound(k);
            if (it != st.end() && speed[*it] >= speed[k]) {
                st.erase(*it);
            }
            else {
                break;
            }
        }
        cout << st.size() << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}