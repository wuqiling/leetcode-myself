#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

class Solution {
   public:
    // dp + dfs
    // time O(N^2) space O(N^2)
    // Runtime: 4 ms, faster than 100.00%
    vector<vector<string>> partition(const string &s) {
        int n = s.size();
        if (n == 0) return {};
        // dp[i][j]=1 => string [i,j] is partition
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                if (i == 0)
                    dp[j][j] = 1;
                else if (i == 1 && s[j] == s[j + i])
                    dp[j][j + i] = 1;
                else if (i > 1 && dp[j + 1][j + i - 1] && s[j] == s[j + i])
                    dp[j][j + i] = 1;
            }
        }
        vector<vector<string>> res;
        vector<string> cur;
        dfs(dp, s, 0, cur, res);
        return res;
    }

   private:
    void dfs(const vector<vector<int>> &dp, const string &s, int start,
             vector<string> &cur, vector<vector<string>> &res) {
        if (start == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i + start < s.size(); ++i) {
            if (dp[start][start + i]) {
                cur.push_back(s.substr(start, i + 1));
                dfs(dp, s, i + start + 1, cur, res);
                cur.pop_back();
            }
        }
    }
};

int main() {
    string s = "aacavcvb";
    vector<vector<string>> ans = Solution{}.partition(s);
    return 0;
}