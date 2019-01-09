#include <algorithm>
#include <string>
#include <unordered_map>

using std::string;
using std::to_string;
using std::unordered_map;

class Solution {
   public:
    // Runtime: 0 ms, faster than 100.00%
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";
        string res;
        // determine the sign
        if ((numerator < 0 && denominator > 0) ||
            (numerator > 0 && denominator < 0))
            res += '-';

        // remove sign of operands
        int64_t n = abs((int64_t)numerator);
        int64_t d = abs((int64_t)denominator);

        // append integral part
        res += to_string(n / d);

        // in case no fractional part
        if (n % d == 0) return res;

        res += '.';

        // fractional part
		// key:val key=  remainder  val = idx of res
        unordered_map<int64_t, size_t> map;

        // division process
        for (int64_t r = n % d; r; r %= d) {
            // meet a know remainder
            if (map.count(r)) {
                res.insert(map[r], 1, '(');
                res += ')';
                break;
            }

            map[r] = res.size();

            r *= 10;

            // append the quotient  digit
            res += to_string(r / d);
        }
        return res;
    }
};

int main() {
    Solution s;

    string ans = s.fractionToDecimal(-1, 0x80000000);
    return 0;
}