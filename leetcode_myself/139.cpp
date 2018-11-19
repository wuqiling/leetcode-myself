#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int N = s.size();
        if (N == 0) return true;

        s = " " + s;
        unordered_set<string> dicHash(wordDict.begin(), wordDict.end());
        vector<int> dp(N + 1, 0);
        dp[0] = 1;  // null str is true
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dicHash.count(s.substr(j + 1, i - j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N];
    }
};

int main() {
    Solution s;
    string s1 = "leetcode";
    vector<string> dic = {"leet", "code"};
    s.wordBreak(s1, dic);
    return 0;
}