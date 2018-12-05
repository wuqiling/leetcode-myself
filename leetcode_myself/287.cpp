#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) { return findDuplicate_3(nums); }

   private:
    // brute force
    // time O(N^2) sapce O(1)
    // runtime 452ms  3.2%
    int findDuplicate_1(const vector<int>& nums) {
        const int N = nums.size();
        for (int i = 1; i <= N - 1; i++) {
            int cnt = 0;
            for (int j = 0; j < N; j++)
                if (nums[j] == i) cnt++;
            if (cnt >= 2) return i;
        }
    }

    // binary search
    // time O(NlgN) space O(1)
    // runtime 12ms 35%
    int findDuplicate_2(const vector<int>& nums) {
        int l = 1, r = nums.size();
        for (; l < r;) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (const auto& p : nums)
                if (p <= m) cnt++;
            if (cnt <= m)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    // Floyd alg
    // time:O(N) space:O(1)
    // run time:4ms 100%
    // 1.define
    // length  of start to input circle:m
    // length of input circle to meet:k
    // circle len:n
    // 2.
    // speed fast=2*slow
    // if fast meet slow => Len(slow)=m+c1*n+k  Len(fast)=2*Len(slow)=m+c2*n+k
    //	=> Len(fast)-Len(slow)=Len(slow)=(c2-c1)*n=c3*n
    // 3.
    // move fast to start
    // speed fast=slow
    // if fast meet input circle node =>Len(fast)=m Len(slow)=c3*n+m
    //	=> fast meet slow in input node !!!
    //
    int findDuplicate_3(const vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        fast = 0;
        do {
            fast = nums[fast];
            slow = nums[slow];
        } while (fast != slow);
        return slow;
    }
};

int main() {
    Solution s;
    int ans = s.findDuplicate(vector<int>{1, 3, 4, 2, 2});

    return 0;
}