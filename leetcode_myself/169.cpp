#include <time.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::swap;
using std::unordered_map;
using std::vector;

// Majority Element
class Solution {
   public:
    int majorityElement(vector<int> &nums) { return majorityElement_4(nums); }

   private:
    // Hash Map(unordered_map)   ---> BST(map  (Red-Black Tree <= AVL Tree))
    // time O(N) space O(N)
    // runtime 8ms 99%
    int majorityElement_1(vector<int> &nums) {
        unordered_map<int, int> map;
        const int t = nums.size() / 2;
        for (const auto &p : nums)
            if (++map[p] > t) return p;
        return 0;
    }

   private:
    // Boyer-Moore vote
    // time O(N) space O(1)
    // runtime 8ms 99%
    int majorityElement_2(vector<int> &nums) {
        int major = INT_MAX;
        for (int i = 0, cnt = 0; i < nums.size(); i++) {
            if (cnt == 0)
                ++cnt, major = nums[i];
            else if (nums[i] == major)
                ++cnt;
            else
                --cnt;
        }
        return major;
    }

   private:
    // randomization
    // time O(N) space O(1) avg 2 loop
    // runtime 8ms 99%
    int majorityElement_3(vector<int> &nums) {
        srand(time(0));
        const int n = nums.size();
        while (1) {
            int idx = rand() % n;
            int majority = nums[idx];
            for (int i = 0, cnt = 0; i < n; i++)
                if (nums[i] == majority && ++cnt > n / 2) return majority;
        }
        return 0;
    }

   private:
    // bit vote
    // time O(32*N) space O(1)
    // runtime 12ms 98%
    int majorityElement_4(vector<int> &nums) {
        const int n = nums.size();
        int majority = 0;
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            int cnt = 0;
            for (const auto &num : nums)
                if (num & mask) ++cnt;
            if (cnt > n / 2) majority |= mask;
        }
        return majority;
    }

   private:
    // full sorting
    // time O(NlgN) space O(1)
    // runtime 12ms 98%
    int majorityElement_5(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

   private:
    // partial sorting
    // time O(N) on avg space O(1)
    // runtime 12ms 98%
    int majorityElement_6(vector<int> &nums) {
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2,
                         nums.end());
        return nums[nums.size() / 2];
    }

   private:
    // divide and conquer
    // time T(N)=2T(N/2)+1 -> O(N)~O(NlgN) space O(NlgN)
	   //runtime 16ms 65%
    int majorityElement_7(vector<int> &nums) {
        return help(nums, 0, nums.size() - 1);
    }
    int help(const vector<int> &nums, int l, int r) {
        if (l == r) return nums[l];
        int m = l + (r - l) / 2;
        int ml = help(nums, l, m);
        int mr = help(nums, m + 1, r);
        if (ml == mr) return ml;
        return count(nums.begin() + l, nums.begin() + r + 1, ml) >
                       count(nums.begin() + l, nums.begin() + r + 1, mr)
                   ? ml
                   : mr;
    }

   private:
    // divaideand conquer
	// time O(N)~O(NlgN) space O(lgN)
    // runtime 8ms 99%
    int majorityElement_8(vector<int> &nums) {
        return help_2(nums, 0, nums.size() - 1).first;
    }
    std::pair<int, int> help_2(const vector<int> &nums, int l, int r) {
        if (l == r) return {nums[l], 1};
        int m = l + (r - l) / 2;
        auto ml = help_2(nums, l, m);
        auto mr = help_2(nums, m + 1, r);
        if (ml.first == mr.first) return {ml.first, ml.second + mr.second};
        if (ml.second > mr.second)
            return {ml.first,
                    ml.second + count(nums.begin() + m + 1,
                                      nums.begin() + r + 1, ml.first)};
        else
            return {mr.first,
                    mr.second + count(nums.begin() + l, nums.begin() + m + 1,
                                      mr.first)};
    }
};

int main() {
    vector<int> nums{3, 2, 4, 3, 3};

    Solution s;
    int ans = s.majorityElement(nums);
    return 0;
}