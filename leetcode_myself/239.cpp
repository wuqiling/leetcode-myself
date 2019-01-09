#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		return maxSlidingWindow_4(nums, k);
	}

   private:
    // brute force
    // time O(N^2) space O(1)
    // Runtime: 160 ms, faster than 4.09%
    vector<int> maxSlidingWindow_1(vector<int>& nums, int k) {
        const int n = nums.size();
        if (!n || k < 0 || k > n) return {};
        vector<int> res;
        for (int i = 0; i < n - k + 1; i++) {
            int maxVal = nums[i];
            for (int j = i + 1; j < k + i; j++) maxVal = max(maxVal, nums[j]);
            res.push_back(maxVal);
        }
        return res;
    }

    // BST/multiset
    // time O(Nlogk) space O(K)
    // Runtime: 80 ms, faster than 22.58%
    vector<int> maxSlidingWindow_2(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> window;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (i - k + 1 >= 0) {
                // push max val
                // time O(1)
                res.push_back(*window.rbegin());
                // only delete one key
                // time logK
                window.erase(window.equal_range(nums[i - k + 1]).first);
            }
        }
        return res;
    }

    // monotonic queue
    class MonotonicQueue {
       public:
        // push an element on the queue
        // will pop all element smaller than e
        void push(int e) {
            while (!data.empty() && e > data.back()) data.pop_back();
            data.push_back(e);
        }
        // pop the max element
        void pop() { data.pop_front(); }
        // get max element
        int getMax() const { return data.front(); }

       private:
        deque<int> data;
    };
	// monotonic queue
    // time O(N) space O(K)
    // Runtime: 80 ms, faster than 22.58%
    vector<int> maxSlidingWindow_3(vector<int>& nums, int k) {
        MonotonicQueue mq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            mq.push(nums[i]);
            if (i - k + 1 >= 0) {
                res.push_back(mq.getMax());
                if (nums[i - k + 1] == mq.getMax()) mq.pop();
            }
        }
        return res;
    }

    // optimzie monotonic queue -> deque
    // time O(N) space O(K)
    // Runtime: 36 ms, faster than 100.00%
    vector<int> maxSlidingWindow_4(vector<int>& nums, int k) {
        deque<int> index;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!index.empty() && nums[i] > nums[index.back()])
                index.pop_back();
            index.push_back(i);
            if (i - k + 1 >= 0) res.push_back(nums[index.front()]);
            if (i - k + 1 >= index.front()) index.pop_front();
        }
        return res;
    }
};