#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    // backtracking
    // runtime ~0 100%
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> res;
        dfs(temp, res, 0, 0, n);
        return res;
    }

   private:
    // cnt count for '(' like stack
    // cntL count all '(' used
    void dfs(string &cur, vector<string> &res, int cnt, int cntL, int n) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            // std::cout << cur << std::endl;
            return;
        }
        // input '('
        if (cntL < n) {
            cur.push_back('(');
            dfs(cur, res, cnt + 1, cntL + 1, n);
            cur.pop_back();
        }
        // input ')'
        if (cnt > 0) {
            cur.push_back(')');
            dfs(cur, res, cnt - 1, cntL, n);
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    return 0;
}