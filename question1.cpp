//Question 1

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countMagicalSubarrays(int n, int k, const vector<int>& arr) {
    unordered_map<int, int> prefixRemainders;
    prefixRemainders[0] = 1;

    int prefixSum = 0;
    int magicalCount = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += arr[i];
        int remainder = ((prefixSum % k) + k) % k;

        if (prefixRemainders.find(remainder) != prefixRemainders.end()) {
            magicalCount += prefixRemainders[remainder];
        }

        prefixRemainders[remainder]++;
    }

    return magicalCount;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << countMagicalSubarrays(n, k, arr) << endl;

    return 0;
}