#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
	   //time O(N) space O(N)
	   //runtime 4ms 36%
    vector<int> plusOne(vector<int>& digits) {
        vector<int> tmp;
        int c = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (i == digits.size() - 1)
                c = c + digits[i] + 1;
            else
                c = c + digits[i];
            tmp.push_back(c % 10);
            c = c > 9 ? 1 : 0;
        }
        if (c != 0) tmp.push_back(1);
        return vector<int>(tmp.rbegin(), tmp.rend());
    }
};

int main() {
    vector<int> digits{9, 9, 9};

    Solution s;
    vector<int> ans = s.plusOne(digits);
    return 0;
}