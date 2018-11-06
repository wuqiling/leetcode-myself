#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;

class Solution
{
  public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		int N = nums.size();
		if (N < 2)
			return {};
		map<int, int> m_hash;
		for (int i = 0; i < N; i++)
		{
			m_hash[nums[i]] = i;
		}
		for (int i = 0; i < N; i++)
		{
			if (m_hash.count(target - nums[i]) > 0 && i != m_hash[target - nums[i]])
				return {i, m_hash[target - nums[i]]};
		}
		return {};
	}
};

int main()
{
	Solution s1;
	vector<int> t = {3, 3, 4};
	vector<int> t2 = s1.twoSum(t, 6);
	return 0;
}