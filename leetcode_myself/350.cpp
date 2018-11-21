#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return intersect_method2(nums1, nums2);
    }

   private:
    // time: O(max(N,M)log(max(N,M))) space:O(max(N,M))
    vector<int> intersect_method1(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size(), M = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        for (int i = 0, j = 0; i < N && j < M; i++, j++) {
            while (i < N && j < M && nums1[i] != nums2[j]) {
                if (nums1[i] < nums2[j])
                    i++;
                else
                    j++;
            }
            if (i < N && j < M) ans.push_back(nums1[i]);
        }
        return ans;
    }

    // time:O(N+M) space:O(max(N,M))
    vector<int> intersect_method2(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect_method2(nums2, nums1);

        unordered_map<int, int> mhash;
        for (const auto& p : nums1) mhash[p]++;

        vector<int> ans;
        for (const auto& p : nums2) {
            if (mhash.count(p) && mhash[p]) {
                mhash[p]--;
                ans.push_back(p);
            }
        }
        return ans;
    }
};