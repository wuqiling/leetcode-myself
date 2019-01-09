#include <iostream>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
   public:

    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> h;
        for (const auto& n : nums) {
			if (!h.count(n))
				h.insert(n);
			else
				return true;
		}
		return false;
    }
};