#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::max;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
		return longestConsecutive_2(nums);
	}

   private:
    // hash map
    // time O(N) space O(N)
    // Runtime: 8 ms, faster than 67.25%
    int longestConsecutive_1(vector<int>& nums) {
        unordered_map<int, int> h;
        for (int n : nums) {
            if (h.count(n)) continue;
            auto it_l = h.find(n - 1);
            auto it_r = h.find(n + 1);
            int l = it_l != h.end() ? it_l->second : 0;
            int r = it_r != h.end() ? it_r->second : 0;
            if (l > 0 && r > 0)
                h[n] = h[n - l] = h[n + r] = l + r + 1;
            else if (l > 0)
                h[n] = h[n - l] = l + 1;
            else if (r > 0)
                h[n] = h[n + r] = r + 1;
            else
                h[n] = 1;
        }

        int res = 0;
        for (const auto& kv : h) res = max(res, kv.second);
        return res;
    }

    // hash set
    // time O(N) space O(N) 每个元素最多访问2次
    // Runtime: 8 ms, faster than 67.25%
    int longestConsecutive_2(vector<int>& nums) {
        unordered_set<int> h(nums.begin(), nums.end());
        int res = 0;
        for (auto n : nums)
            if (!h.count(n - 1)) {
                int len = 0;
                while (h.count(n++)) len++;
                res = max(res, len);
            }
        return res;
    }
};