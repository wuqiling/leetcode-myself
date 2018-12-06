#include <stack>
#include <string>
using std::stack;
using std::string;

class Solution {
   public:
    // time O(N) space O(N)
    // runtime ~0 100%
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[':
                    st.push(s[i]);
                    break;
                case ')':
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else
                        return false;
                    break;
                default:
                    break;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    bool ans = s.isValid("]");
    return 0;
}