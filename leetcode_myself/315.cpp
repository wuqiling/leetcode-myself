#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using std::vector;
using std::set;
using std::unordered_map;

class Solution {
public:
	//FenwickTree
	//time O(NlogN) space O(N)
	//Runtime: 36 ms, faster than 48.21%
	vector<int> countSmaller(vector<int>& nums) {
		set<int>sorted(nums.begin(), nums.end());
		//map the number to its rank
		unordered_map<int, int>ranks;
		int rank = 0;
		for (const auto &n : sorted)
			ranks[n] = ++rank;
		vector<int>res;
		FenwickTree tree(ranks.size());

		//scan the numbers in reversed order
		for (int i = (int)nums.size() - 1; i >= 0; --i) {
			//check how many numbers are samller than the current number
			res.push_back(tree.query(ranks[nums[i]] - 1));
			//increase the count the the rank of current number
			tree.update(ranks[nums[i]], 1);
		}
		return vector<int>(res.rbegin(), res.rend());
	}
private:
	//??
	class FenwickTree {
	public:
		FenwickTree(int n):sum_(n+1,0){}
		void update(int i, int delta) {
			while (i < sum_.size()) {
				sum_[i] += delta;
				i += lowbit(i);
			}
		}
		int query(int i)const {
			int sum = 0;
			while (i > 0) {
				sum += sum_[i];
				i -= lowbit(i);
			}
			return sum;
		}
	private:
		static int lowbit(int x) { return x&(-x); }
		vector<int>sum_;
	};
};