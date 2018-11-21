#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashs1;
        for (const auto& p : nums1) hashs1.insert(p);
        unordered_set<int> ansSet;
        for (const auto& p : nums2)
            if (hashs1.find(p) != hashs1.end()) ansSet.insert(p);

        return vector<int>(ansSet.begin(), ansSet.end());
    }
};

int main() {
    vector<int> n1 = {1, 2, 2, 1}, n2 = {2, 2};
    Solution s;
    vector<int> ans = s.intersection(n1, n2);
    return 0;
}