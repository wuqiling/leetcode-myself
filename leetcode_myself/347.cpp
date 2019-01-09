#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {}

   private:
    // hash map + sort
    // time O(NlogN) space O(N)
    // Runtime: 12 ms, faster than 99.44%
    vector<int> topKFrequent_1(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for (const auto& n : nums) hm[n]++;
        vector<pair<int, int>> hmSort;
        for (const auto& kv : hm) hmSort.push_back({kv.second, kv.first});
        sort(hmSort.begin(), hmSort.end());
        vector<int> res;
        for (int i = 0, n = hmSort.size(); i < k && i < hm.size(); i++)
            res.push_back(hmSort[n - i - 1].second);
        return res;
    }

    // hash map + heap
    // time O(NlogK) space O(N)
    // Runtime: 20 ms, faster than 44.51%
    //队列一样，只能从队尾添加(插入)元素，从队头(队首)删除元素。
    //但他有一个特性，就是队列中最大的元素总是位于队首，所以出队时，并非按先进先出的原则进行，而是将当前队列中最大的元素出队
    vector<int> topKFrequent_2(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for (const auto& n : nums) hm[n]++;
        vector<int> res;
        // pair<first,second> first is frequency second is number
        priority_queue<pair<int, int>> pq;
        for (const auto& kv : hm) {
            pq.push({kv.second, kv.first});  // logk
            if (pq.size() > (int)hm.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{1, 1, 1, 2, 2, 3};

    Solution s;
    vector<int> ans = s.topKFrequent(nums, 2);
    return 0;
}