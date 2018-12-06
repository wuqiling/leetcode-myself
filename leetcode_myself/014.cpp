#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
   public:
    // brute force
    // time O(N*M) space O(1)
    // runtime ~0 100%
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        if (N == 0) return "";
        if (N == 1) return strs[0];
        for (int i = 0; i < strs[0].size(); i++) {
            int j = 1;
            for (; j < N; j++)
                if (strs[0][i] != strs[j][i]) break;
            if (j != N) return strs[0].substr(0, i);
        }
        return strs[0];
    }
};

int main() {
    Solution s;
    vector<string> strs = {"d", "d", "d"};
    string ans = s.longestCommonPrefix(strs);
    return 0;
}