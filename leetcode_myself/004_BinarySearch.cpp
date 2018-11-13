#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

static const auto io_sync_off = []() {
	std::ios::sync_with_stdio(false); // dont use scanf and printf after this
	std::cin.tie(
		nullptr); // cin will flush if cout is used while cin is tied to cout
	return nullptr;
}();

class Solution {
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		const int M1 = nums1.size();
		const int M2 = nums2.size();
		if (M1 > M2)
			return findMedianSortedArrays(nums2, nums1);

		int start = 0, end = M1;
		const int K = (M1 + M2 + 1) / 2;
		int part1, part2, maxL1, minR1, maxL2, minR2;
		while (start <= end) {
			part1 = (start + end) / 2;
			part2 = K - part1;

			// if part1 is 0 it means nothing is there on left side
			// if part1 is len of input then there is nothing on right side
			maxL1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
			minR1 = (part1 == M1) ? INT_MAX : nums1[part1];

			maxL2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
			minR2 = (part2 == M2) ? INT_MAX : nums2[part2];

			if (maxL1 <= minR2 && maxL2 <= minR1) {
				// we have partitioned array correct
				if ((M1 + M2) % 2 == 0)
					return (myMax(maxL1, maxL2) + myMin(minR1, minR2)) * 0.5;
				else
					return myMax(maxL1, maxL2);
			}
			else if (maxL1 > minR2)
				end = part1 - 1;
			else
				start = part1 + 1;
		}
	}

private:
	inline int myMax(int a, int b) { return a > b ? a : b; }
	inline int myMin(int a, int b) { return a > b ? b : a; }
};


int main() {
	Solution s1;
	vector<int> n1 = { 1,2,3 };
	vector<int>n2 = { 4,5 };
	double ans = s1.findMedianSortedArrays(n1, n2);
	cout << ans;
	return 0;
}