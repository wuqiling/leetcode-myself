#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::set;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return wordBreak_2(s, wordDict);
    }

   private:
    // dp + dfs
    // time O(N^2) space O(N^2)
    // Runtime: 16 ms, faster than 20.51%
    vector<string> wordBreak_1(string s, vector<string>& wordDict) {
        n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // dp[i][j]=1 -> s[i,j] in wordDict
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j + i < n; ++j)
                if (wordSet.count(s.substr(j, i + 1))) dp[j].push_back(j + i);

        vector<string> res;
        vector<int> cur;
        dfs(dp, s, cur, 0, res);
        return res;
    }

   private:
    int n;
    set<std::pair<int, int>> subUsed;
    void dfs(const vector<vector<int>>& dp, const string& s, vector<int>& cur,
             int start, vector<string>& res) {
        if (start == n) {
            int spaceCnt = cur.size();
            int len = spaceCnt + n - 1;
            string t(len, ' ');
            spaceCnt -= 2;
            for (int i = len - 1, sidx = n - 1; i >= 0; --i) {
                if (spaceCnt >= 0 && sidx == cur[spaceCnt]) {
                    t[i] = ' ';
                    --spaceCnt;
                } else {
                    t[i] = s[sidx--];
                }
            }
            res.push_back(t);
            subUsed.erase(subUsed.begin(), subUsed.end());
            return;
        }
        for (int i = 0; i < dp[start].size(); ++i) {
            if (subUsed.count({start, dp[start][i]}))
                continue;
            else
                subUsed.insert({start, dp[start][i]});
            cur.push_back(dp[start][i]);
            dfs(dp, s, cur, dp[start][i] + 1, res);
            cur.pop_back();
        }
    }



    // dp + dfs
    // time O(N^2) space O(N^2)
    // Runtime: 8 ms, faster than 81.37%
    vector<string> wordBreak_2(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);
    }

   private:
    // key string + all(val) = all ans of string
    unordered_map<string, vector<string>> mem;
    vector<string> append(const vector<string>& pre, const string& word) {
        vector<string> results;
        // all result end with word
        for (const auto& p : pre) results.push_back(p + " " + word);
        return results;
    }
    const vector<string>& wordBreak(const string& s,
                                    const unordered_set<string>& dict) {
        // already know the answer of s
        if (mem.count(s)) return mem[s];

        // answer for s
        vector<string> ans;

        // s in dict add it to the ans array
        if (dict.count(s)) ans.push_back(s);
        for (int j = 1; j < s.size(); ++j) {
            const string& right = s.substr(j);
            if (!dict.count(right)) continue;

            // get the ans for left part
            const string& left = s.substr(0, j);
            const vector<string> left_ans =
                append(wordBreak(left, dict), right);
            ans.insert(ans.end(), left_ans.begin(), left_ans.end());
        }
        mem[s].swap(ans);
        return mem[s];
    }
};

int main() {
    string s =
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaa";
    vector<string> wd{"a",         "aa",        "aaa",     "aaaa",
                      "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                      "aaaaaaaaa", "aaaaaaaaaa"};
    vector<string> ans = Solution{}.wordBreak(s, wd);
    return 0;
}