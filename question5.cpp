//Question 5

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool differByOne(const string &word1, const string &word2) {
    int differences = 0;
    for (int i = 0; i < word1.size(); ++i) {
        if (word1[i] != word2[i]) {
            ++differences;
            if (differences > 1) return false;
        }
    }
    return differences == 1;
}

int findMinTransformations(int n, int m, vector<string> &dictionary, const string &start, const string &target) {
    unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
    wordSet.insert(start); // Ensure the start word is part of the set

    if (wordSet.find(target) == wordSet.end()) {
        return -1;
    }

    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        pair<string, int> front = q.front();
        string currentWord = front.first;
        int steps = front.second;
        q.pop();

        if (currentWord == target) {
            return steps;
        }

        for (int i = 0; i < m; ++i) {
            string nextWord = currentWord;
            for (char c = 'a'; c <= 'z'; ++c) {
                nextWord[i] = c;
                if (nextWord != currentWord && wordSet.find(nextWord) != wordSet.end() && visited.find(nextWord) == visited.end()) {
                    q.push({nextWord, steps + 1});
                    visited.insert(nextWord);
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> dictionary(n);
    for (int i = 0; i < n; ++i) {
        cin >> dictionary[i];
    }

    string start, target;
    cin >> start >> target;

    int result = findMinTransformations(n, m, dictionary, start, target);
    cout << result << endl;

    return 0;
}
