#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

/**
 * dp[i][j]= string s with len i matches string p with j  :s[0-i] match p[0-j]
 * 1. base case
 * 2. update function
 * 3. goal


 1. p[j]=s[i]:dp[i][j]=dp[i-1][j-1]
 2. p[j]=".":dp[i][j]=dp[i-1][j-1]
 3. p[j]="*":
                a. p[j-1]!=s[i]:dp[i][j]=dp[i][j-2]//a*=>empty
                b. p[j-1]=s[i] or p[j-1]=".":
                        dp[i][j]=dp[i][j-1]//a* => a
                        dp[i][j]=dp[i-1][j]//a* => aaa...
                        dp[i][j]=dp[i][j-2]//a* => empty

TIME :O(M*N)   SPACE:O(M*N)
 */
class Solution {
   public:
    bool isMatch(string s, string p) {
        const int S = s.size(), P = p.size();
        //base on len
        vector<vector<bool>> dp(S + 1, vector<bool>(P + 1, false));

        // base case
        dp[0][0] = true;
        for (int i = 0; i < P; i++)
            if (p[i] == '*' && dp[0][i - 1]) dp[0][i + 1] = true;

        //
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < P; j++) {
                if (p[j] == s[i])
                    dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if (p[j] == '*') {
                    if (p[j - 1] != s[i] && p[j - 1] != '.')
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    else
                        dp[i + 1][j + 1] =
                            dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1];

                } else
                    dp[i + 1][j + 1] = false;
            }
        }
        return dp[S][P];
    }
};

int main() {
    Solution s;
    s.isMatch("", ".*");
    return 0;
}