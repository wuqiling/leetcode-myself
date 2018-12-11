#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
   public:
    // time O(M*N) space O(M*N)
    // dp[i][j] string s[0:i] match sring p[0:j]
    // dp[i][j] = dp[i-1][j-1] 			  if s[i]=p[j] || p[j] ='?'
    //			  dp[i-1][j]||dp[i][j-1]  if p[j]='*'
    //
    // runtime 36ms 76%
    bool isMatch(string s, string p) {
        // remove multiple '*'
        // eg a***b => a*b
        string p2;
        for (int i = 0; i < p.size(); i++) {
            while (p[i] == '*' && i + 1 < p.size() && p[i + 1] == '*') i++;
            p2 += p[i];
        }

        // initial
        vector<vector<int>> dp(s.size() + 1, vector<int>(p2.size() + 1, 0));
        // base
        dp[0][0] = 1;
        if (dp[0].size() > 1 && p2[0] == '*') dp[0][1] = 1;
        // state equations
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 1; j < p2.size() + 1; j++) {
                if (p2[j - 1] == '?' || p2[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p2[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp[s.size()][p2.size()];
    }
};

int main() {
    Solution s;
    bool ans = s.isMatch("aa", "*");
    return 0;
}