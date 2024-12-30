//Question 2

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool differByOne(const string& word1, const string& word2) {
    int diffCount = 0;
    for (int i = 0; i < word1.size(); ++i) {
        if (word1[i] != word2[i]) {
            ++diffCount;
            if (diffCount > 1) return false;
        }
    }
    return diffCount == 1;
}

int shortestTransformationSequence(int n, const string& beginWord, const string& endWord, vector<string>& wordList) {
    sort(wordList.begin(), wordList.end());
    unordered_set<string> validWords;

    for (int i = 0; i < wordList.size(); ++i) {
        if (i % 2 == 0) {
            validWords.insert(wordList[i]);
        }
    }

    if (validWords.find(endWord) == validWords.end()) return 0;

    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({beginWord, 1});
    visited.insert(beginWord);

    while (!q.empty()) {
        auto [currentWord, steps] = q.front();
        q.pop();

        if (currentWord == endWord) return steps;

        for (const string& word : validWords) {
            if (visited.find(word) == visited.end() && differByOne(currentWord, word)) {
                q.push({word, steps + 1});
                visited.insert(word);
            }
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    string beginWord, endWord;
    cin >> beginWord >> endWord;

    vector<string> wordList(n);
    for (int i = 0; i < n; ++i) {
        cin >> wordList[i];
    }

    cout << shortestTransformationSequence(n, beginWord, endWord, wordList) << endl;

    return 0;
}
