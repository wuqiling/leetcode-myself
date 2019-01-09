#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    // time O(N) space O(N)
    // Runtime: 20 ms, faster than 77.62%
    string convert(string s, int numRows) {
        const int n = s.size();
        if (numRows <= 1 || n <= 1) return s;
        vector<string> vs(numRows, "");
        int idx = 0;
        while (idx < n) {
            for (int i = 0; i < numRows && idx < n; i++) vs[i] += s[idx++];
            for (int i = numRows - 2; i > 0 && idx < n; i--) vs[i] += s[idx++];
        }
        string res;
        for (const auto &i : vs) res += i;
        return res;
    }
};

int main() {
    string s = "PAYPALISHIRING";

    Solution st;
    string ans = st.convert(s, 3);
    return 0;
}