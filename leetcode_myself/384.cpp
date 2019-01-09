#include <vector>
using std::vector;
using std::swap;

//time O(N) space O(N)
//Runtime: 228 ms, faster than 48.71%
class Solution {
   public:
    Solution(vector<int> nums) : num_(nums){}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { 
		return num_; 
	}

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() { 
		vector<int>res(num_);
		int n = res.size();
		for (int i = 0; i + 1 < res.size(); ++i) {
			int idx = rand() % (n - i) + i;
			swap(res[i], res[idx]);
		}
		return res;
	}

   private:
    vector<int> num_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


int main() {
	vector<int>num{ 1,2,3 };
	vector<int>pa1 = Solution{ num }.shuffle();
	return 0;
}