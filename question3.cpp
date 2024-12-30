//Question 3

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string toBinary(int num) {
    string binary = "";
    if (num == 0) return "0";
    while (num > 0) {
        binary = char((num % 2) + '0') + binary;
        num /= 2;
    }
    return binary;
}

vector<int> binarySort(const vector<int>& nums) {
    vector<pair<string, int>> binaryPairs;

    for (int num : nums) {
        binaryPairs.emplace_back(toBinary(num), num);
    }

    stable_sort(binaryPairs.begin(), binaryPairs.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first < b.first;
    });

    vector<int> sortedNums;
    for (const auto& pair : binaryPairs) {
        sortedNums.push_back(pair.second);
    }

    return sortedNums;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> sortedNums = binarySort(nums);

    for (int num : sortedNums) {
        cout << num << " ";
    }

    return 0;
}