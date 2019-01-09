#include <vector>

using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
	// runtime 8ms
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (cur > min2)
                return true;
			else if (cur < min1) 
				min1 = cur;
            else if (cur > min1 && cur < min2)
                min2 = cur;
        }
        return false;
    }
};