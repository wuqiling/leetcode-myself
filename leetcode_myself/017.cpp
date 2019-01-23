#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    // dfs
    // time O(3^n)~O(4^n),space O(n)
    // runtime ~0 100%
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        const vector<string> k2str{"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string tmp;
        dfs(k2str, res, digits, tmp, 0);
        return res;
    }

   private:
    void dfs(const vector<string> &k2str, vector<string> &res, string &num,
             string &str, int pos) {
        if (pos == num.size()) return res.push_back(str);

        for (int j = 0; j < k2str[num[pos] - '0'].size(); j++) {
            str.push_back(k2str[num[pos] - '0'][j]);
            dfs(k2str, res, num, str, pos + 1);
            str.pop_back();
        }
    }
};

int main() {
    string d = "";
    Solution s;
    vector<string> ans = s.letterCombinations(d);
    return 0;
}