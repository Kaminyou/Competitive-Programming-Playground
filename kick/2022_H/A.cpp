#include <iostream>
using namespace std;

long long solve() {
    int L;
    int N;
    cin >> L >> N;

    int status = 0; // -1: anticlockwise, 1: clockwise
    int direction = 0;  // -1: anticlockwise, 1: clockwise
    long long location = 0;
    long long cnt = 0;
    for (int i = 0; i < N; ++i) {
        int D;
        char C;
        cin >> D;
        cin >> C;
        if (C == 'C') {
            if (location == 0) {
                long long nextLoc = location + D;
                cnt += nextLoc / L;
                location = nextLoc % L;
                direction = 1;
            }
            else {
                long long nextLoc = location + D;
                int round = nextLoc / L;
                cnt += round;
                location = nextLoc % L;
                if (round > 0 && direction == -1) cnt--;
                if (round > 0) direction = 1;
            }
        }
        else { // C == 'A'
            if (location == 0) {
                long long nextLoc = location + D;
                int round = nextLoc / L;
                cnt += round;
                location = L - nextLoc % L;
                direction = -1;
            }
            else {
                long long nextLoc = (L - location) + D;
                int round = nextLoc / L;
                cnt += round;
                location = L - nextLoc % L;
                if (round > 0 && direction == 1) cnt--;
                if (round > 0) direction = -1;
            }
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        long long ans = solve();
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}