#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

class Solution {
   public:
    // math
    // time O(N) space O(1)
    // Runtime: 4 ms, faster than 76.77%
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0)
                res.push_back("FizzBuzz");
            else if (i % 3 == 0)
                res.push_back("Fizz");
            else if (i % 5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};

int main() {
    vector<string> ans = Solution{}.fizzBuzz(15);
    return 0;
}