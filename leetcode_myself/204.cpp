#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int countPrimes(int n) { return countPrimes_2(n); }

   private:
    int countPrimes_1(int n) {
        int cnt = 0;
        for (int i = 1; i < n; i++)
            if (isPrime(i)) cnt++;

        return cnt;
    }

   private:
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) return false;
        return true;
    }

    // time O(N lg lg N) space  O(n)
    int countPrimes_2(int n) {
        vector<int> table(n, 0);
        for (int i = 2; i < n; i++) table[i] = 1;

        for (int i = 2; i * i < n; i++) {
            if (!table[i]) continue;
            for (int j = i * i; j < n; j += i) table[j] = 0;
        }
        int cnt = 0;
        for (int i = 2; i < n; i++)
            if (table[i]) cnt++;
        return cnt;
    }
};

int main() {
    Solution s;
    int ans = s.countPrimes(10);
    return 0;
}