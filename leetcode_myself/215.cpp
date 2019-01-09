#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_2(nums, k);
    }

   private:
    // stl heap max-heap by default
    // time O(N lgN) space O(N)
    // Runtime: 16 ms, faster than 37.73%
    int findKthLargest_1(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) pq.pop();
        return pq.top();
    }

    // stl heap min-heap by default
    // time O(NlgK) space O(K)
    int findKthLargest_2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, myCompare> pq;
        for (auto& n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                cout << pq.top() << " ";
                pq.pop();
            }
        }
        return pq.top();
    }
    struct myCompare {
        bool operator()(const int a, const int b) { return a > b; }
    };

    // quick sort
    // time O(NlgN) space O(1)
    // Runtime: 56 ms, faster than 12.59%
    int findKthLargest_3(vector<int>& nums, int k) {
        const int n = nums.size();
        if (!n) return 0;
        int start = 0, end = n - 1;
        while (1) {
            int token = partion(nums, start, end);
            if (token + 1 == k) return nums[token];
            if (token + 1 > k)
                end = token - 1;
            else
                start = token + 1;
        }
        return 0;
    }

    // largest to small
    int partion(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int l = start + 1, r = end;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[l], nums[start]);
        return r;
    }

    // heap by code
    int heap_size;
    int left(int idx) { return (idx << 1) + 1; }
    int right(int idx) { return (idx << 1) + 2; }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--) max_heapify(nums, i);
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx, l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void max_heap_pop(vector<int>& nums) {
        swap(nums[0], nums[heap_size - 1]);
        heap_size--;
        max_heapify(nums, 0);
    }
    int max_heap_top(vector<int>& nums) { return nums[0]; }
	// max-heap
	// time O(N lgN) space O(N)
	// Runtime: 12 ms, faster than 53.53%
    int findKthLargest_4(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k - 1; i++) max_heap_pop(nums);
        return max_heap_top(nums);
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5};

    Solution s;
    int ans = s.findKthLargest(nums, 3);
    return 0;
}