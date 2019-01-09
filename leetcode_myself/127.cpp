#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::max;
using std::min;
using std::queue;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        return ladderLength_3(beginWord, endWord, wordList);
    }

   private:
    // dfs
    // Time Limit Exceeded
    int ladderLength_1(string beginWord, string endWord,
                       vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                int cnt = 0;
                for (int k = 0; k < wordList[0].size(); ++k) {
                    if (wordList[i][k] != wordList[j][k] && ++cnt >= 2) break;
                }
                if (cnt == 1) {
                    wordMap[wordList[i]].push_back(j);
                    wordMap[wordList[j]].push_back(i);
                }
            }
        }
        if (wordMap.count(beginWord) == 0) {
            for (int i = 0; i < wordList.size(); ++i) {
                int cnt = 0;
                for (int k = 0; k < wordList[0].size(); ++k)
                    if (beginWord[k] != wordList[i][k] && ++cnt >= 2) break;
                if (cnt == 1) wordMap[beginWord].push_back(i);
            }
        }
        if (wordMap[beginWord].size() == 0) return 0;
        int res = INT_MAX;
        vector<int> status(wordList.size(), 0);  // 0:word not used 1:word used
        dfs(beginWord, endWord, wordList, status, 0, res);
        return res == INT_MAX ? 0 : res;
    }

   private:
    unordered_map<string, vector<int>> wordMap;
    void dfs(const string& curWord, string& endWord, vector<string>& wordList,
             vector<int>& status, int curLen, int& res) {
        if (curWord == endWord) {
            res = min(res, curLen + 1);
            return;
        }
        if (curLen >= res) return;
        for (auto& idx : wordMap[curWord]) {
            if (status[idx]) continue;
            status[idx] = 1;
            dfs(wordList[idx], endWord, wordList, status, curLen + 1, res);
            status[idx] = 0;
        }
    }

   private:
    // bfs
    // time O(N*26^L) space O(N) L=len(word) N=len(wordList)
    // Runtime: 88 ms, faster than 67.50%
    int ladderLength_2(string beginWord, string endWord,
                       vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int wLen = beginWord.size();
        int step = 0;
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {
                string w = q.front();
                q.pop();
                for (int i = 0; i < wLen; i++) {
                    char tmp = w[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == tmp) continue;
                        w[i] = ch;
                        if (w == endWord) return step + 1;
                        if (!wordSet.count(w)) continue;
                        wordSet.erase(w);
                        q.push(w);
                    }
                    w[i] = tmp;
                }
            }
        }
        return 0;
    }

    // bidirectional bfs
    // time O(N*26^(L/2)) space O(N)
    // Runtime: 28 ms, faster than 93.10%
    int ladderLength_3(string beginWord, string endWord,
                       vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        unordered_set<string> q1{beginWord}, *p_q1;
        unordered_set<string> q2{endWord}, *p_q2;
        int step = 0;
        int wlen = beginWord.size();
        while (!q1.empty() && !q2.empty()) {
            ++step;
            if (q1.size() > q2.size()) {
                p_q1 = &q2;
                p_q2 = &q1;
            } else {
                p_q1 = &q1;
                p_q2 = &q2;
            }
            unordered_set<string> q;
            for (string w : *p_q1) {
                for (int i = 0; i < wlen; ++i) {
                    char tmp = w[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == tmp) continue;
                        w[i] = ch;
                        if ((*p_q2).count(w)) return step + 1;
                        if (!wordSet.count(w)) continue;
                        wordSet.erase(w);
                        q.insert(w);
                    }
                    w[i] = tmp;
                }
            }
            swap(*p_q1, q);
        }
        return 0;
    }
};

int main() {
    vector<string> wordlist{"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    int ans = s.ladderLength("hit", "cog", wordlist);
    return 0;
}