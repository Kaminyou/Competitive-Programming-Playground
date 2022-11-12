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
    int getRange(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }
};

int main() {
    int T, N;
    cin >> N;
    cin >> T;
    BIT* rowBIT = new BIT(N);
    BIT* colBIT = new BIT(N);
    vector<int> rowCount(N + 1, 0);
    vector<int> colCount(N + 1, 0);

    int t, a, b, c,d;
    while (T--) {
        scanf("%d%d%d", &t, &a, &b);
        if (t == 1) {
            if (rowCount[a] == 0) rowBIT->update(a, 1);
            if (colCount[b] == 0) colBIT->update(b, 1);
            ++rowCount[a];
            ++colCount[b];
        }
        else if (t == 2) {
            if (rowCount[a] == 1) rowBIT->update(a, -1);
            if (colCount[b] == 1) colBIT->update(b, -1);
            --rowCount[a];
            --colCount[b];
        }
        else {
            scanf("%d%d", &c, &d);
            int rowSum = rowBIT->getRange(a, c);
            int colSum = colBIT->getRange(b, d);
            if ((rowSum == c - a + 1) || (colSum == d - b + 1)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}