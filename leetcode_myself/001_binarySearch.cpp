#include <iostream>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;

class Solution
{
  public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		int N = nums.size();
		if (N < 2)
			return {};

		//memorize index
		vector<pair<int, int>> index;
		for (int i = 0; i < N; i++)
		{
			index.push_back(std::make_pair(nums[i], i));
		}

		//sort
		sort(index.begin(), index.end());
		int begin = 0;
		int end = N - 1;

		//binary search
		while (begin < end)
		{
			if (index[begin].first + index[end].first == target)
			{
				return {index[begin].second, index[end].second};
			}
			else if (index[begin].first + index[end].first < target)
			{
				begin++;
			}
			else
			{
				end--;
			}
		}
		return {};
	}
};

int main()
{
	vector<int> a = {3, 2, 4};
	Solution aa;
	vector<int> b = aa.twoSum(a, 6);
	return 0;
}