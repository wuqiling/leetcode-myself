#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
   public:
    // Runtime: 8 ms, faster than 68.05%
    int evalRPN(const vector<string>& tokens) {
        stack<int64_t> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+")
                calc(st, '+');
            else if (tokens[i] == "-")
                calc(st, '-');
            else if (tokens[i] == "*")
                calc(st, '*');
            else if (tokens[i] == "/")
                calc(st, '/');
            else {
                if (tokens[i].size() == 0) continue;
                int64_t num = 0;
                int64_t sign = 1;
                if (tokens[i][0] == '-')
                    sign = -1;
                else if (tokens[i][0] == '+')
                    sign = 1;
                else
                    num = tokens[i][0] - '0';
                for (int j = 1; j < tokens[i].size(); j++)
                    num = num * 10 + tokens[i][j] - '0';
                st.push(sign * num);
            }
        }
        return st.top();
    }

   private:
    void calc(stack<int64_t>& st, const char ch) {
        int64_t a = st.top();
        st.pop();
        int64_t b = st.top();
        st.pop();
        int64_t res;
        switch (ch) {
            case '+':
                res = b + a;
                break;
            case '-':
                res = b - a;
                break;
            case '*':
                res = b * a;
                break;
            case '/':
                if (!a) exit(1);
                res = b / a;
                break;
            default:
                break;
        }
        st.push(res);
    }
};

int main() {
    vector<string> tmp{"3", "-4", "+"};

    Solution s;
    int ans = s.evalRPN(tmp);
    return 0;
}