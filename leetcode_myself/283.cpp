#include <iostream>
#include <vector>

using std::swap;
using std::vector;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) { moveZeroes_1(nums); }

   private:
    // time O(N) space O(1)
    // runtime 8ms 100%
    void moveZeroes_1(vector<int>& nums) {
        for (int l = 0, r = 0;; l++, r++) {
            while (l < nums.size() && nums[l]) l++;
            if (l == nums.size()) break;
            while (r < nums.size() && (!nums[r] || r < l)) r++;
            if (r == nums.size()) break;
            swap(nums[l], nums[r]);
        }
    }

    // time O(N) space O(1)
	// runtime 12ms 63%
    void moveZeroes_2(vector<int>& nums) {
        int cur = 0;
        // move all the nonzero elements advance
		for (int i = 0; i < nums.size(); i++) 
			if (nums[i]) nums[cur++] = nums[i];
		
        for (; cur < nums.size(); cur++) nums[cur] = 0;
    }
};

int main() {
    vector<int> a{0,1,0,3,12,0,0,3,0,6,7,8,9,0,11,12};
    Solution s;
    s.moveZeroes(a);
    return 0;
}