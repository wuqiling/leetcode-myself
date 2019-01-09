#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
   public:
    // dfs
    // time O(26*N) space O(N)
    // Runtime: 0 ms, faster than 100.00%
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (k <= 0) return n;
		k_ = k;

        int res = 0;
        dfs(s, 0, n - 1, res);
        return res;
    }

   private:
    int k_;
    void dfs(const string &s, int l, int r, int &res) {
        if (l > r || r - l + 1 <= res) return;
        // std::cout << s.substr(l, r - l + 1) << std::endl;
        vector<int> mp(26, 0);
        for (int i = l; i <= r; ++i) ++mp[s[i] - 'a'];
        bool valid = true;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] && mp[i] < k_) {
                valid = false;
                break;
            }
        }
        if (valid) {
            res = max(res, r - l + 1);
            return;
        }
        for (int i = l; i <= r; i++) {
            if (mp[s[i] - 'a'] && mp[s[i] - 'a'] < k_) {
                dfs(s, l, i - 1, res);
                l = i + 1;
            }
        }
        dfs(s, l, r, res);
    }
};

int main() {
    int ans = Solution().longestSubstring("bbaaacbd", 3);
    return 0;
}