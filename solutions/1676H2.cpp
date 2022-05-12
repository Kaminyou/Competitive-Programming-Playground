#include <iostream>
#include <vector>
using namespace std;

class BIT {
private:
    vector<int> tree;
public:
    BIT(int size) {
        tree = vector<int>(size + 1, 0);
    }
    int lsb(int x) {
        return x & (-x);
    }
    void update(int index, int value) {
        while (index < tree.size()) {
            tree[index] += value;
            index += lsb(index);
        }
    }
    int getSum(int index) {
        int sum = 0;
        while (index) {
            sum += tree[index];
            index -= lsb(index);
        }
        return sum;
    }
};

void solve(vector<int>& arr) {
    int n = arr.size();

    BIT* bit = new BIT(n); 
    long long res = 0;
    for (int i = n - 1; i >= 0; --i) {
        int x = arr[i];
        res += bit->getSum(x);
        bit->update(x, 1);
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) cin >> arr[i];
        solve(arr);
    }
}