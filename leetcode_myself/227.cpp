#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
   public:
    // stack
    // time O(N) space O(N)
    // 4ms 100%
    int calculate(string s) {
        if (s.size() == 0) return 0;
        stack<char> sc;
        stack<int> sn;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = s[i] - '0';
                while (i + 1 < s.size() & s[i + 1] >= '0' && s[i + 1] <= '9')
                    num = num * 10 + s[++i] - '0';
                sn.push(num);
            } else if (s[i] == '*' || s[i] == '/') {
                while (!sc.empty() && (sc.top() == '*' || sc.top() == '/'))
                    calc(sc, sn);
                sc.push(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                while (!sc.empty()) calc(sc, sn);
                sc.push(s[i]);
            }
        }
        while (!sc.empty()) calc(sc, sn);
        return sn.top();
    }

   private:
    void calc(stack<char>& sc, stack<int>& sn) {
        int a = sn.top(); sn.pop();
        int b = sn.top(); sn.pop();
        switch (sc.top()) {
            case '+': sn.push(b + a); break;
            case '-': sn.push(b - a); break;
            case '*': sn.push(b * a); break;
            case '/': if (!a) exit(1); sn.push(b / a); break;
            default: break;
        }
        sc.pop();
    }
};

int main() {
    Solution s;
    int ans = s.calculate("");
    return 0;
}