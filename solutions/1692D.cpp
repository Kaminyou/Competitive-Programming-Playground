#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    string currTime;
    int period;
    cin >> currTime;
    cin >> period;
    int hour = stoi(currTime.substr(0, 2));
    int minute = stoi(currTime.substr(3, 2));

    unordered_set<string> hash;

    int res = 0;
    int i = 0;
    bool once = false;
    while (true) {
        // currTime + i minute
        int currMinute = minute + i;
        int currHour = (hour + currMinute / 60) % 24;
        currMinute = currMinute % 60;
        // check go back
        if (currMinute == minute && currHour == hour) 
        {
            if (once) break;
            once = true;
        }
        string currMinuteStr;
        string currHourStr;
        if (currMinute < 10) {
            currMinuteStr = "0" + to_string(currMinute);
        }
        else currMinuteStr = to_string(currMinute);
        if (currHour < 10) {
            currHourStr = "0" + to_string(currHour);
        }
        else currHourStr = to_string(currHour);
        //cout << currHourStr + ":" + currMinuteStr << endl;
        if (currMinuteStr[0] == currHourStr[1] && currMinuteStr[1] == currHourStr[0]) {
            if (hash.find(currHourStr) != hash.end()) break;
            hash.insert(currHourStr);
        }

        i += period;
    }
    cout << hash.size() << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}