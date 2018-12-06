#include <iostream>
#include <string>

using std::string;


class Solution {
   public:
    // time O(N) space O(N)
    // runtime ~0ms 100%
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        string res = "11";
        for (int i = 2; i < n; i++) {
            string cur;
            for (int j = 0, Num = res[0], Cnt = 1; j < res.size();) {
                while (j + 1 < res.size() && res[j + 1] == Num) j++, Cnt++;
                cur += Cnt + '0';
                cur += Num;
                j++;
                if (j >= res.size()) break;
                Num = res[j];
                Cnt = 1;
            }
            res = cur;
            // std::cout << i + 1 << ": " << res << std::endl;
        }
        return res;
    }
};

int main() {
    Solution s;
    string ans = s.countAndSay(10);
    std::cout << ans << std::endl;
    return 0;
}