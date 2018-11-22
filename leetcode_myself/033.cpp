#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        return search_method2(nums, target);
    }

   private:
    // time:O(log(N)) space:O(1)
    // 4ms 98%
    int search_method1(vector<int>& nums, int target) {
        const int N = nums.size();
        if (N == 0) return -1;
        for (int l = 0, r = N - 1; l <= r;) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) {
                if (nums[l] < nums[r])
                    l = mid + 1;
                else {
                    if (target < nums[l])
                        // l---||--mid---target---r
                        l = mid + 1;
                    else if (target > nums[l]) {
                        if (nums[l] < nums[mid])
                            // l---mid---target--||---r
                            l = mid + 1;
                        else if (nums[r] == target)
                            return r;  // right corner
                        else
                            // l---target---||---mid---r
                            r = mid - 1;
                    } else
                        return l;  // left corner
                }
            } else if (nums[mid] > target) {
                if (nums[l] < nums[r])
                    r = mid - 1;
                else {
                    if (target > nums[l])
                        // l----target----mid---||---r
                        r = mid - 1;
                    else if (target < nums[l]) {
                        if (nums[l] < nums[mid])
                            // l----mid---||--target---r
                            l = mid + 1;
                        else if (nums[r] == target)
                            return r;  // right corner
                        else
                            // l---||--target---mid---r
                            r = mid - 1;
                    } else
                        return l;  // left cornet
                }

            } else  // nums[mid]==target
                return mid;
        }
        return -1;
    }

    // time:O(log(N)) space:O(1)
    // 8ms 22%
    int search_method2(vector<int>& nums, int target) {
        const int N = nums.size();
        if (N == 0) return -1;
        int lo = 0, hi = N - 1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at
        // least 1. Proof by contradiction that mid < hi: if mid==hi, then
        // lo==hi and loop would have been terminated.
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }
        // lo==hi is the index of the smallest value and also the number of
        // places rotated.
        int rot = lo;
        lo = 0, hi = N - 1;
        // The usual binary search and accounting for rotation.
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int realmid = (mid + rot) % N;
            if (nums[realmid] == target) return realmid;
            if (nums[realmid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> n = {3};
    int t = 3;
    int ans = s.search(n, t);
    return 0;
}