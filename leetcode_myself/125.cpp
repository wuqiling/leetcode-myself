#include <string>

using std::string;

class Solution {
   public:
    // time 2*O(N) space O(N)
    // runtime 8ms 61%
    bool isPalindrome(string s) { return isPalindrome_2(s); }

   private:
    // time O(N) space O(N)
    // runtime 8ms 61%
    bool isPalindrome_1(string s) {
        string t;
        for (const auto &p : s)
            if (p >= 'A' && p <= 'Z')
                t += char(p + 'a' - 'A');
            else if (p >= 'a' && p <= 'z')
                t += p;
            else if (p >= '0' && p <= '9')
                t += p;
        for (int i = 0; i < t.size() / 2; i++)
            if (t[i] != t[t.size() - i - 1]) return false;
        return true;
    }

    // time O(N) space O(1)
    bool isPalindrome_2(const string &s) {
        for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
            while (!isalnum(s[l]) && l < r) l++;
            while (!isalnum(s[r]) && l < r) r--;
            if (toupper(s[l]) != toupper(s[r])) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    bool ans = s.isPalindrome("PP----p");
    return 0;
}