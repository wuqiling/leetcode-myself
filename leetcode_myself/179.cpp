#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

using std::swap;
using std::to_string;

class Solution {
   public:
    // quick sort
    // time O(NlogN) space O(N)
    // Runtime: 0 ms, faster than 100.00%
    string largestNumber(vector<int> &nums) {
        vector<vector<string>> numsS(10);
        for (auto &n : nums) {
            string s = to_string(n);
            numsS[s[0] - '0'].push_back(s);
        }
        string res;
        for (int i = 9; i > 0; --i) {
            quick_sort(numsS[i]);
            for (auto &s : numsS[i])
                if (s.size()) res += s;
        }
        if (res.size())
            res.append(numsS[0].size(), '0');
        else if (!res.size() && nums.size())
            return "0";
        return res;
    }

   private:
    void quick_sort(vector<string> &nums) {
        if (!nums.size()) return;
        quick_sort(nums, 0, (int)nums.size() - 1);
    }
    void quick_sort(vector<string> &nums, int start, int end) {
        if (start >= end) return;
        int pivote = partion(nums, start, end);
        quick_sort(nums, start, pivote - 1);
        quick_sort(nums, pivote + 1, end);
    }
    int partion(vector<string> &nums, int start, int end) {
        int l = start, r = end - 1;
        while (l <= r) {
            if (larger(nums[l], nums[end]))//Descending
                ++l;
            else if (larger(nums[end], nums[r]))
                --r;
            else
                swap(nums[l++], nums[r--]);
        }
        swap(nums[l], nums[end]);
        return l;
    }
    bool larger(const string &a, const string &b) const {
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;
        for (int i = 0; i < n; i++) {
            char ch1 = i < n1 ? a[i] : b[i - n1];
            char ch2 = i < n2 ? b[i] : a[i - n2];
            if (ch1 > ch2)
                return true;
            else if (ch1 < ch2)
                return false;
        }
        return n1 < n2;
    }
};

int main() {
    vector<int> nums{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    string ans = Solution{}.largestNumber(nums);
    return 0;
}