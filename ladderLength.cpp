#include "util.h"

class Solution {
private:
    int count(const string &word1, const string &word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        int count = 0;
        for (size_t i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) {
                count++;
            }
        }
        return count;
    }

    vector<string> findSatisfiedWords(const std::string &word, const vector<string> &wordList) {
        vector<string> words;
        for (const string &s: wordList) {
            if (count(word, s) == 1) {
                words.push_back(s);
            }
        }
        return words;
    }

    std::unordered_map<string, std::vector<string>> buildNeighbors(std::string beginWord, vector<string>& wordList) {
        std::unordered_map<string, vector<string>> neighbors;
        neighbors[beginWord] = findSatisfiedWords(beginWord, wordList);
        for (const string &s: wordList) {
            neighbors[s] = findSatisfiedWords(s, wordList);
        }
        return neighbors;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() == 1) {
            for (auto s: wordList) {
                if (s == endWord) {
                    return 1;
                }
            }
            return 0;
        }
        auto neighbors = buildNeighbors(beginWord, wordList);
        std::queue<string> q;
        std::unordered_set<string> visited;
        visited.reserve(100);
        q.push(beginWord);
        visited.insert(beginWord);

        for (int step = 0; !q.empty(); step++) {
            const size_t level_size = q.size();
            for (size_t i = 0; i < level_size; i++) {
                auto current = q.front();
                q.pop();
                if (current == endWord) return step;
                for (string neighbor: neighbors[current]) {
                    if (visited.insert(neighbor).second) {
                        q.push(std::move(neighbor));
                    }
                }
            }
        }
        return 0;
    }
};