//Question 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    if (w < n - 1) {
        cout << "infinity" << endl;
        return 0;
    }

    vector<vector<int>> schedule(w, vector<int>(n));
    int isolation = (w - 1) / (n - 1);

    for (int week = 0; week < w; ++week) {
        for (int team = 0; team < n; ++team) {
            schedule[week][team] = ((team + week) % 2) + 1;
        }
    }

    cout << isolation << endl;

    for (int week = 0; week < w; ++week) {
        for (int team = 0; team < n; ++team) {
            cout << schedule[week][team];
        }
        cout << endl;
    }

    return 0;
}