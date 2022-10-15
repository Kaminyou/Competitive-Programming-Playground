#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<int> t2s(26, -1);
    vector<bool> used(26, false);
    string res;
    for (auto& c : t) {
        // find
        if (t2s[c - 'a'] != -1) {
            //cout << "case 1" << endl;
            res.push_back(t2s[c - 'a'] + 'a');
        }
        else {
            //cout << "case 2" << endl;
            bool flag = false;
            for (int i = 0; i < 26 && flag == false; ++i) {
                //cout << "try " << c << " -> "<< i <<" " <<(char)(i + 'a') << endl;
                if (used[i]) continue;
                if (i == c - 'a') continue;
                // target i
                int current = i;
                
                if (t2s[current] == -1) {
                    t2s[c - 'a'] = current;
                    used[current] = true;
                    res.push_back(t2s[c - 'a'] + 'a');
                    flag = true;
                }
                else {
                    // have previous one
                    current = t2s[current];
                    int path = 1;
                    while (current != -1) {
                        if (current == (c - 'a')) break;
                        current = t2s[current];
                        path++;
                        //if (path >= 26) break;
                    }
                    //cout << current << " " << path << endl;
                    if (current != -1 && path < 25) continue;
                    t2s[c - 'a'] = i;
                    used[i] = true;
                    res.push_back(t2s[c - 'a'] + 'a');
                    flag = true;
                }
            }

        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
