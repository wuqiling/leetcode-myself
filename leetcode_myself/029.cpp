#include <vector>

using std::vector;

class Solution {
   public:
    int divide(int dividend, int divisor) {
        return divide_method2(dividend, divisor);
    }

   private:
    // time:O(N) space:O(1)
    // Time Limit Exceeded
    int divide_method1(int dividend, int divisor) {
        if (divisor == 0 || dividend == 0) return 0;
        bool isNeg =
            (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        int64_t l_n1 = abs(dividend * 1LL);
        int64_t l_n2 = abs(divisor * 1LL);
        int64_t ans = 0;
        for (int64_t sum = l_n2; sum <= l_n1; sum += l_n2) ans++;
        return isNeg ? (ans * -1 < INT_MIN ? INT_MIN : ans * -1)
                     : (ans > INT_MAX ? INT_MAX : ans);
    }

    // time:O(log(N)) space:O(1)
    // 12ms 98%
    int divide_method2(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int isNeg = -1;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            isNeg = 1;
        uint32_t a = abs(dividend);
        uint32_t b = abs(divisor);
        uint32_t ans = 0;
        while (a >= b) {
            uint32_t sum = b;
            uint32_t count = 1;
            while (sum + sum <= a && sum + sum > sum) {  // avoid overflow
                sum += sum;
                count += count;
            }
            a -= sum;
            ans += count;
        }
        return isNeg * ans;
    }
};

int main() {
    Solution s;
    int ans = s.divide((int)0x80000000, -1);
    return 0;
}