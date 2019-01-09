#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) { return isPalindrome_3(x); }

   private:
    // time O(N) space O(N)
    // runtime 212ms 20%
    bool isPalindrome_1(int x) {
        if (x < 0) return false;
        string s;
        for (int i = x; i != 0; i /= 10) s += to_string(i % 10);
        for (int lo = 0, hi = (int)s.size() - 1; lo < hi; ++lo, --hi)
            if (s[lo] != s[hi]) return false;
        return true;
    }

    // stack
    // time O(N) space O(N)
    // Runtime: 124 ms, faster than 81.11%
    bool isPalindrome_2(int x) {
        if (x < 0) return false;
        stack<int> st;
        for (int n = x; n != 0; n /= 10) st.push(n % 10);
        for (int n = x; n >= 10; n /= 10, st.pop())
            if (n % 10 != st.top()) return false;
        return true;
    }

	//time O(N) space O(1)
    //Runtime: 244 ms, faster than 10.78%
    bool isPalindrome_3(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0, tmp = x;
        while (tmp) {
            sum = sum * 10 + tmp % 10;
            tmp /= 10;
        }
        return x == sum;
    }
};

int main() {
    Solution s;
    bool ans = s.isPalindrome(12221);
    return 0;
}